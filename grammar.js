const OPS = [
  '+', '-', '/', '*', '**', '%', '<', '>', '<=', '>=', '<<', '>>', '>>>', '&',
  '|', '^', '==', '!=',
];

const COMPOUND_OPS = [
  '+=', '-=', '/=', '*=', '**=', '%=', '<<=', '>>=', '>>>=', '&=', '|=', '^=',
];

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
        field('name', alias($.method_name, $.identifier)),
        field('arguments', optional(alias($.extern_arguments, $.arguments))),
        field('returns', optional($._returns)),
        field('body', optional($.block)),
      )
    ),
    extern_arguments: $ => seq(
      '(',
      optional(seq($.argument, repeat(seq(',', $.argument)))),
      optional(choice(',', seq(',', $.rest_argument, optional(',')))),
      ')'
    ),
    module_method: $ => seq(
      'fn',
      field('visibility', optional($.visibility)),
      field('modifier', optional(alias($.inline, $.modifier))),
      field('name', alias($.method_name, $.identifier)),
      field('type_parameters', optional($.type_parameters)),
      field('arguments', optional(alias($.method_arguments, $.arguments))),
      field('returns', optional($._returns)),
      field('body', $.block),
    ),
    method_name: $ => choice(/[a-zA-Z\d_\$]+(=|\?)?/, ...OPS),
    method_arguments: $ => seq('(', comma_list($.argument), ')'),
    argument: $ => seq(
      field('name', $.identifier),
      ':',
      field('type', $._type),
    ),
    rest_argument: _ => '...',
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
      $.copy,
      $.generic_type,
      alias($.constant, $.type),
    ),
    _method_modifier: _ => choice(
      'mut',
      'move',
      'static',
      'async',
      'async mut',
      'inline',
      'inline mut',
      'inline move',
      'inline static',
      'inline async',
      'inline async mut',
    ),

    // Classes
    class: $ => seq(
      'type',
      field('visibility', optional($.visibility)),
      field('modifier', optional(alias($._class_modifier, $.modifier))),
      field('name', $.constant),
      field('type_parameters', optional($.type_parameters)),
      field('body', $.class_body),
    ),
    _class_modifier: $ => choice(
      'async',
      'builtin',
      'copy',
      'extern',
      'inline',
      seq(optional(choice('inline', 'copy')), 'enum'),
    ),
    class_body: $ => seq('{', repeat($._class_expression) , '}'),
    _class_expression: $ => choice(
      $.define_field,
      $.define_case,
      alias($.class_method, $.method),
    ),
    define_field: $ => seq(
      'let',
      field('visibility', optional($.visibility)),
      field('name', $.field),
      ':',
      field('type', $._type),
    ),
    define_case: $ => seq(
      'case',
      field('name', $.constant),
      field('arguments', optional(alias($.case_arguments, $.arguments))),
    ),
    case_arguments: $ => seq('(', comma_list($._type), ')'),
    class_method: $ => seq(
      'fn',
      field('visibility', optional($.visibility)),
      field('modifier', optional(alias($._method_modifier, $.modifier))),
      field('name', alias($.method_name, $.identifier)),
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
      field('name', alias($.method_name, $.identifier)),
      field('type_parameters', optional($.type_parameters)),
      field('arguments', optional(alias($.method_arguments, $.arguments))),
      field('returns', optional($._returns)),
      field('body', optional($.block)),
    ),
    _trait_method_modifier: _ => choice(
      'mut',
      'move',
      'inline',
      'inline mut',
      'inline move',
    ),
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
      field('bounds', optional($.bounds)),
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
      prec.right(alias($.constant, $.type)),
      $.ref_type,
      $.mut_type,
      $.uni_type,
      $.fn_type,
      $.tuple_type,
      $.move_type,
    ),
    generic_type: $ => seq(
      field('name', $.constant),
      field('arguments', $.type_arguments),
    ),
    type_arguments: $ => seq('[', comma_list($._type), ']'),
    ref_type: $ => seq('ref', field('type', $._type)),
    mut_type: $ => seq('mut', field('type', $._type)),
    uni_type: $ => seq('uni', field('type', $._type)),
    move_type: $ => seq('move', field('type', $._type)),
    fn_type: $ => prec.right(
      seq(
        'fn',
        field('modifier', optional(alias($.move, $.modifier))),
        field('arguments', optional(alias($.fn_type_arguments, $.arguments))),
        field('returns', optional($._returns)),
      )
    ),
    fn_type_arguments: $ => seq('(', comma_list($._type), ')'),
    tuple_type: $ => seq('(', comma_list($._type), ')'),

    // Expressions
    block: $ => seq('{', repeat($._expression), '}'),
    _expression: $ => choice(
      $.binary,
      $.define_variable,
      $.float,
      $.integer,
      $.self,
      $.nil,
      $.true,
      $.false,
      $.block,
      $.string,
      alias($.and_or, $.binary),
      $.cast,
      $.grouped_expression,
      $.tuple,
      $.array,
      $.break,
      $.return,
      $.next,
      $.try,
      $.throw,
      $.closure,
      $.field,
      $.if,
      $.while,
      $.loop,
      $.for,
      $.match,
      $.ref,
      $.mut,
      $.recover,
      prec.right($.identifier),
      $.call,
      $.constant,
      alias($.call_with_receiver, $.call),
      $.assign_receiver_field,
      $.assign_local,
      $.assign_field,
      $.replace_local,
      $.replace_field,
      $.compound_assign_local,
      $.compound_assign_field,
      $.compound_assign_receiver_field,
    ),

    // Assignments
    assign_receiver_field: $ => prec.right(
      3,
      seq(
        field('receiver', $._expression),
        '.',
        field('name', $._call_name),
        '=',
        field('value', $._expression)
      )
    ),
    assign_local: $ => seq(
      field('name', $.identifier),
      '=',
      field('value', $._expression),
    ),
    assign_field: $ => seq(
      field('name', $.field),
      '=',
      field('value', $._expression),
    ),
    replace_local: $ => seq(
      field('name', $.identifier),
      ':=',
      field('value', $._expression),
    ),
    replace_field: $ => seq(
      field('name', $.field),
      ':=',
      field('value', $._expression),
    ),
    compound_assign_local: $ => seq(
      field('name', $.identifier),
      choice(...COMPOUND_OPS),
      field('value', $._expression),
    ),
    compound_assign_field: $ => seq(
      field('name', $.field),
      choice(...COMPOUND_OPS),
      field('value', $._expression),
    ),
    compound_assign_receiver_field: $ => prec.right(
      3,
      seq(
        field('receiver', $._expression),
        '.',
        field('name', choice($.identifier, $.constant, $.integer)),
        choice(...COMPOUND_OPS),
        field('value', $._expression)
      )
    ),

    // Method calls
    _call_name: $ => choice(
      // Identifiers are aliased as "name" such that highliths don't conflict
      // with locals (e.g. ensuring `name` in `self.name` doesn't get
      // highlighted as a variable if a local variable with the same name
      // exists).
      alias($.identifier_with_special, $.name),
      alias($.identifier, $.name),
      alias($.constant, $.name),
      $.integer,
    ),
    call: $ => choice(
      seq(field('name', alias($.identifier_with_special, $.name))),
      seq(
        field('name', $._call_name),
        field('arguments', alias($.call_arguments, $.arguments)),
      )
    ),
    call_arguments: $ => seq(
      token.immediate('('),
      comma_list($._call_argument),
      ')',
    ),
    _call_argument: $ => choice(
      $._expression,
      $.named_argument,
    ),
    named_argument: $ => seq(
      field('name', $.identifier),
      ':',
      field('value', $._expression)
    ),
    call_with_receiver: $ => prec.right(
      3,
      seq(
        field('receiver', $._expression),
        '.',
        field('name', $._call_name),
        field('arguments', optional(alias($.call_arguments, $.arguments))),
      ),
    ),

    // Borrows
    ref: $ => prec.right(seq('ref', $._expression)),
    mut: $ => prec.right(seq('mut', $._expression)),
    recover: $ => prec.right(seq('recover', $._expression)),

    // Sequences
    grouped_expression: $ => seq('(', $._expression ,')'),
    tuple: $ => seq('(', $._expression, ',', comma_list($._expression), ')'),
    array: $ => seq('[', comma_list($._expression), ']'),

    // Control flow
    return: $ => prec.right(seq(
      'return',
      optional(seq(token.immediate(/[ \t]+/), optional($._expression))),
    )),
    try: $ => seq('try', $._expression),
    throw: $ => seq('throw', $._expression),

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

    // Loops
    while: $ => seq(
      'while',
      field('condition', $._expression),
      field('body', $.block),
    ),
    loop: $ => seq('loop', field('body', $.block)),
    for: $ => seq(
      'for',
      field('pattern', $._pattern),
      'in',
      field('iterator', $._expression),
      field('body', $.block),
    ),

    // Pattern matching
    match: $ => seq(
      'match',
      field('value', $._expression),
      '{',
      field('cases', optional($.cases)),
      '}'
    ),
    cases: $ => seq(
      $.case,
      repeat(seq(optional(','), $.case)),
      optional(','),
    ),
    case: $ => seq(
      'case',
      field('pattern', $._pattern),
      field('guard', optional(seq('if', $._expression))),
      '->',
      field('body', $._expression),
    ),
    _pattern: $ => choice(
      $.wildcard_pattern,
      alias($.identifier, $.identifier_pattern),
      alias($.integer, $.integer_pattern),
      alias($.string, $.string_pattern),
      alias($.constant, $.constant_pattern),
      alias($.namespaced_constant_pattern, $.constant_pattern),
      $.enum_pattern,
      $.class_pattern,
      $.tuple_pattern,
      $.or_pattern,
      $.boolean_pattern,
      $.mutable_pattern,
    ),
    mutable_pattern: $ => seq('mut', alias($.identifier, $.identifier_pattern)),
    wildcard_pattern: $ => '_',
    tuple_pattern: $ => seq('(', comma_list($._pattern), ')'),
    enum_pattern: $ => seq(
      field('name', $.constant),
      field('arguments', alias($.enum_pattern_arguments, $.arguments)),
    ),
    enum_pattern_arguments: $ => seq('(', comma_list($._pattern), ')'),
    class_pattern: $ => seq('{', comma_list($.field_pattern), '}'),
    field_pattern: $ => seq(
      field('name', $.field),
      '=',
      field('pattern', $._pattern),
    ),
    or_pattern: $ => prec.left(
      seq($._pattern, repeat1(prec.left(seq('or', $._pattern)))),
    ),
    boolean_pattern: $ => choice('true', 'false'),
    namespaced_constant_pattern: $ => seq(
      field('receiver', $.identifier),
      '.',
      field('name', $.constant),
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
      field('visibility', optional($.visibility)),
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
          choice(...OPS),
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
          alias('$', $.string_content),
          alias(/[^'\$\\]+/, $.string_content),
        )),
        "'"
      ),
      seq(
        '"',
        repeat(choice(
          $.interpolation,
          $.escape_sequence,
          alias('$', $.string_content),
          alias(/[^"\$\\]+/, $.string_content),
        )),
        '"'
      ),
    ),
    escape_sequence: _ => choice(
      seq('\\u{', /[a-fA-F0-9]*/, '}'),
      '\\\\',
      /\\[a-z0\$'"]/,
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
    inline: _ => 'inline',
    copy: _ => 'copy',
    move: _ => 'move',
    visibility: _ => 'pub',
    line_comment: _ => token(prec(-1, seq('#', /.*/))),
    identifier: _ => /([a-z]|_)[a-zA-Z\d_]*/,
    identifier_with_special: _ => /([a-z]|_)[a-zA-Z\d_\$]*\??/,
    field: _ => /@[a-zA-Z\d_]+/,
    constant: _ => /[A-Z][a-zA-Z\d_]*/
  }
});
