function list(rule, sep, trailing) {
  const steps = [rule, repeat(seq(sep, rule))];

  if (trailing) {
    steps.push(optional(sep));
  }

  return optional(seq(...steps));
}

function comma_list(rule) {
  return list(rule, ',', true);
}

function import_as(rule, alias) {
  return seq(field('name', rule), field('alias', seq('as', alias)));
}

module.exports = grammar({
  name: 'inko',
  word: $ => $.identifier,
  extras: $ => [
    $.line_comment,
    /\s/,
  ],

  rules: {
    source_file: $ => repeat($._root),
    _root: $ => choice(
      $.extern_import,
      $.import,
      $.external_function,
      alias($.module_method, $.method),
      $.class,
      $.trait,
      $.implement_trait,
      $.reopen_class,
      $._expression,
      $.define_constant,
    ),

    // Imports
    import: $ => prec.right(
      seq(
        'import',
        field('path', $.path),
        field('symbols', optional($.symbols)),
        field('tags', optional($.tags)),
      )
    ),
    path: $ => seq($.identifier, repeat(seq('.', $.identifier))),
    symbols: $ => seq(
      '(',
      comma_list(choice($.import_as, $.self, $.constant, $.identifier)),
      ')'
    ),
    import_as: $ => choice(
      import_as($.self, $.identifier),
      import_as($.identifier, $.identifier),
      import_as($.constant, $.constant),
    ),
    tags: $ => prec.right(seq('if', list($.identifier, 'and', false))),
    extern_import: $ => prec.right(
      seq(
        'import',
        'extern',
        field('path', alias($.extern_import_path, $.path)),
        field('tags', optional($.tags)),
      ),
    ),
    extern_import_path: $ => seq('"', /[^"]*/, '"'),

    // Methods
    //
    // The right precedence is needed here such that the function body doesn't
    // conflict with block _expressions_.
    external_function: $ => prec.right(
      seq(
        'fn',
        field('visibility', optional($.visibility)),
        'extern',
        field('name', $.identifier),
        field('arguments', optional(alias($.extern_arguments, $.arguments))),
        field('returns', optional($._returns)),
        field('body', optional($.block)),
      )
    ),
    extern_arguments: $ => seq(
      '(',
      optional(seq($.argument, repeat(seq(',', $.argument)))),
      optional(choice(seq(','), seq(',', $.rest_argument, optional(',')))),
      ')'
    ),
    module_method: $ => seq(
      'fn',
      field('visibility', optional($.visibility)),
      field('name', $.identifier),
      field('type_parameters', optional($.type_parameters)),
      field('arguments', optional(alias($.method_arguments, $.arguments))),
      field('returns', optional($._returns)),
      field('body', $.block),
    ),
    method_arguments: $ => seq('(', comma_list($.argument), ')'),
    argument: $ => seq(
      field('name', $.identifier),
      ':',
      field('type', $._type),
    ),
    rest_argument: _ => seq('...'),
    _returns: $ => seq('->', $._type),
    type_parameters: $ => seq('[', comma_list($.type_parameter), ']'),
    type_parameter: $ => seq(
      field('name', $.constant),
      field(
        'requirements',
        optional(alias($.type_parameter_requirements, $.requirements))
      ),
    ),
    type_parameter_requirements: $ => seq(
      ':',
      list($._type_parameter_requirement, '+', false),
    ),
    _type_parameter_requirement: $ => choice(
      $.mutable,
      $.generic_type,
      alias($.constant, $.type),
    ),
    _method_modifier: _ => choice(
      'mut',
      'move',
      'async mut',
      'async',
      'static',
    ),

    // Classes
    class: $ => seq(
      'class',
      field('visibility', optional($.visibility)),
      field('modifier', optional(alias($._class_modifier, $.modifier))),
      field('name', $.constant),
      field('type_parameters', optional($.type_parameters)),
      field('body', $.class_body),
    ),
    _class_modifier: $ => choice('async', 'builtin', 'enum'),
    class_body: $ => seq('{', repeat($._class_expression) , '}'),
    _class_expression: $ => choice(
      $.define_field,
      $.case,
      alias($.class_method, $.method),
    ),
    define_field: $ => seq(
      'let',
      field('name', $.field),
      ':',
      field('type', $._type),
    ),
    case: $ => seq(
      'case',
      field('name', $.constant),
      field('arguments', optional(alias($.case_arguments, $.arguments))),
    ),
    case_arguments: $ => seq('(', comma_list($._type), ')'),
    class_method: $ => seq(
      'fn',
      field('visibility', optional($.visibility)),
      field('modifier', optional(alias($._method_modifier, $.modifier))),
      field('name', $.identifier),
      field('type_parameters', optional($.type_parameters)),
      field('arguments', optional(alias($.method_arguments, $.arguments))),
      field('returns', optional($._returns)),
      field('body', $.block),
    ),

    // Traits
    trait: $ => seq(
      'trait',
      field('visibility', optional($.visibility)),
      field('name', $.constant),
      field('type_parameters', optional($.type_parameters)),
      field('requirements', optional($.required_traits)),
      field('body', $.trait_body),
    ),
    trait_body: $ => seq('{', repeat(alias($.trait_method, $.method)) , '}'),
    trait_method: $ => seq(
      'fn',
      field('visibility', optional($.visibility)),
      field('modifier', optional(alias($._trait_method_modifier, $.modifier))),
      field('name', $.identifier),
      field('type_parameters', optional($.type_parameters)),
      field('arguments', optional(alias($.method_arguments, $.arguments))),
      field('returns', optional($._returns)),
      field('body', optional($.block)),
    ),
    _trait_method_modifier: _ => choice('mut', 'move'),
    required_traits: $ => seq(':', list($._required_trait, '+', false)),
    _required_trait: $ => choice($.generic_type, alias($.constant, $.type)),

    // Implementing traits
    implement_trait: $ => seq(
      'impl',
      field('trait', choice($.generic_type, alias($.constant, $.type))),
      'for',
      field('class', $.constant),
      field('bounds', optional($.bounds)),
      field('body', $.implement_trait_body),
    ),
    implement_trait_body: $ => seq(
      '{',
      repeat(alias($.class_method, $.method)) ,
      '}'
    ),
    bounds: $ => seq('if', comma_list($.bound)),
    bound: $ => seq(
      field('name', $.constant),
      field('requirements', alias($.bound_requirements, $.requirements)),
    ),
    bound_requirements: $ => seq(
      ':',
      list($._type_parameter_requirement, '+', false),
    ),

    // Reopening classes
    reopen_class: $ => seq(
      'impl',
      field('name', $.constant),
      field('body', $.reopen_class_body),
    ),
    reopen_class_body: $ => seq(
      '{',
      repeat(alias($.class_method, $.method)) ,
      '}'
    ),

    // Type signatures
    _type: $ => choice(
      prec.left($.generic_type),
      prec.left(alias($.constant, $.type)),
      $.ref_type,
      $.mut_type,
      $.uni_type,
      $.fn_type,
      $.tuple_type,
    ),
    generic_type: $ => seq(
      field('name', $.constant),
      field('arguments', $.type_arguments),
    ),
    type_arguments: $ => seq('[', comma_list($._type), ']'),
    ref_type: $ => seq('ref', field('type', $._type)),
    mut_type: $ => seq('mut', field('type', $._type)),
    uni_type: $ => seq('uni', field('type', $._type)),
    fn_type: $ => prec.right(
      seq(
        'fn',
        field('arguments', optional(alias($.fn_type_arguments, $.arguments))),
        field('returns', optional($._returns)),
      )
    ),
    fn_type_arguments: $ => seq('(', comma_list($._type), ')'),
    tuple_type: $ => seq('(', comma_list($._type), ')'),

    // Expressions
    block: $ => seq('{', repeat($._expression), '}'),
    _expression: $ => choice(
      $.define_variable,
      $.float,
      $.integer,
      $.self,
      $.nil,
      $.true,
      $.false,
      $.block,
      $.string,
      $.identifier,
      alias($.and_or, $.binary),
      $.cast,
      $.binary,
      $.grouped_expression,
      $.tuple,
      $.array,
      $.break,
      $.return,
      $.next,
      $.try,
      $.closure,
      $.field,
      $.if,
      prec.right(0, $.constant),
      prec.right(1, $.instance),
    ),

    // Sequences
    grouped_expression: $ => seq('(', $._expression ,')'),
    tuple: $ => seq('(', $._expression, ',', comma_list($._expression), ')'),
    array: $ => seq('[', comma_list($._expression), ']'),

    // Control flow
    return: $ => seq(
      'return',
      optional(seq(token.immediate(/[ \t]+/), $._expression)),
    ),
    try: $ => seq('try', $._expression),

    if: $ => seq(
      'if',
      field('condition', $._expression),
      field('consequence', $.block),
      repeat(field('alternative', $.else_if)),
      field('alternative', optional($.else)),
    ),
    else_if: $ => seq(
      'else',
      'if',
      field('condition', $._expression),
      field('consequence', $.block),
    ),
    else: $ => seq('else', field('body', $.block)),

    // Class instance expressions
    instance: $ => seq(
      field('name', $.constant),
      field('fields', $.instance_fields),
    ),
    instance_fields: $ => seq(
      '{',
      comma_list($.assign_field),
      '}'
    ),
    assign_field: $ => seq(
      field('name', $.field),
      '=',
      field('value', $._expression)
    ),

    // Closures
    closure: $ => seq(
      'fn',
      field('modifier', optional(alias($.move, $.modifier))),
      field('arguments', optional(alias($.closure_arguments, $.arguments))),
      field('returns', optional($._returns)),
      field('body', $.block),
    ),
    closure_arguments: $ => seq(
      '(',
      comma_list(alias($.closure_argument, $.argument)),
      ')'
    ),
    closure_argument: $ => seq(
      field('name', $.identifier),
      optional(seq(':', field('type', $._type))),
    ),

    // let definitions
    define_constant: $ => seq(
      'let',
      field('name', $.constant),
      '=',
      field('value', $._expression),
    ),
    define_variable: $ => prec.left(
      0,
      seq(
        'let',
        field('modifier', optional(alias($.mutable, $.modifier))),
        field('name', $.identifier),
        field('type', optional(seq(':', $._type))),
        '=',
        field('value', $._expression),
      ),
    ),

    // Binary expressions
    and_or: $ => prec.left(
      1,
      seq(
        field('left', $._expression),
        field('operator', choice('and', 'or')),
        field('right', $._expression)
      )
    ),
    binary: $ => prec.left(
      2,
      seq(
        field('left', $._expression),
        field(
          'operator',
          choice(
            '+', '-', '/', '*', '**', '%', '<', '>', '<=', '>=', '<<', '>>',
            '>>>', '&', '|', '^', '==', '!=',
          ),
        ),
        field('right', $._expression),
      )
    ),
    cast: $ => prec.left(
      2,
      seq(
        field('expression', $._expression),
        'as',
        field('type', $._type),
      )
    ),

    // Numbers
    float: _ => /-?\d[\d_]*((e|E)(\+|-)?|\.)[\d_]+/,
    integer: _ => /-?(0x[\da-fA-F_]+|\d[\d_]*)/,

    // Strings
    string: $ => choice(
      seq(
        "'",
        repeat(choice(
          $.interpolation,
          $.escape_sequence,
          alias(/[^'\$\\]+/, $.string_content),
        )),
        "'"
      ),
      seq(
        '"',
        repeat(choice(
          $.interpolation,
          $.escape_sequence,
          alias(/[^"\$\\]+/, $.string_content),
        )),
        '"'
      ),
    ),
    escape_sequence: _ => choice(
      seq('\\u{', /[a-fA-F0-9]*/, '}'),
      /\\[a-z\$'"]/
    ),
    interpolation: $ => seq('${', repeat($._expression), '}'),

    // Various terminals (e.g. identifiers)
    self: _ => 'self',
    nil: _ => 'nil',
    true: _ => 'true',
    false: _ => 'false',
    break: _ => 'break',
    next: _ => 'next',
    mutable: _ => 'mut',
    move: _ => 'move',
    visibility: _ => 'pub',
    line_comment: _ => token(seq('#', /.*/)),
    identifier: _ => /([a-z]|_)[a-zA-Z\d_]*/,
    field: _ => /@[a-zA-Z\d_]+/,
    constant: _ => /[A-Z][a-zA-Z\d_]*/
  }
});
