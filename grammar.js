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
      $.module_method,
      $.class,
      $.trait,
      $.implement_trait,
      $.reopen_class,
      $._expression,
    ),

    // Imports
    import: $ => seq(
      'import',
      field('path', $.path),
      field('symbols', optional($.symbols)),
      field('tags', optional($.tags)),
    ),
    path: $ => seq($.identifier, repeat(seq('.', $.identifier))),
    symbols: $ => seq('(', comma_list($._symbol), ')'),
    _symbol: $ => choice($.import_as, $.self, $.constant, $.identifier),
    import_as: $ => choice(
      import_as($.self, $.identifier),
      import_as($.identifier, $.identifier),
      import_as($.constant, $.constant),
    ),
    tags: $ => seq('if', list($.identifier, 'and', false)),
    extern_import: $ => seq(
      'import',
      'extern',
      field('path', alias($.extern_import_path, $.path)),
      field('tags', optional($.tags)),
    ),
    extern_import_path: $ => seq('"', /[^"]*/, '"'),

    // Methods
    external_function: $ => seq(
      'fn',
      field('visibility', optional($.visibility)),
      'extern',
      field('name', $.identifier),
      field('arguments', optional(alias($.extern_arguments, $.arguments))),
      field('returns', optional($._returns)),
      field('body', optional($.block)),
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
      alias($.mutable_requirement, $.mut),
      $.generic_type,
      alias($.constant, $.type),
    ),
    mutable_requirement: _ => 'mut',
    visibility: _ => 'pub',
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
      $.field,
      $.case,
      alias($.class_method, $.method),
    ),
    field: $ => seq(
      'let',
      field('name', $.field_name),
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
      $.generic_type,
      alias($.constant, $.type),
      $.ref_type,
      $.mut_type,
      $.uni_type,
      $.fn_type,
    ),
    generic_type: $ => seq(
      field('name', $.constant),
      field('arguments', $.type_arguments),
    ),
    type_arguments: $ => seq('[', comma_list($._type), ']'),
    ref_type: $ => seq('ref', field('type', $._type)),
    mut_type: $ => seq('mut', field('type', $._type)),
    uni_type: $ => seq('uni', field('type', $._type)),
    fn_type: $ => seq(
      'fn',
      field('arguments', optional(alias($.fn_type_arguments, $.arguments))),
      field('returns', optional($._returns)),
    ),
    fn_type_arguments: $ => seq('(', comma_list($._type), ')'),

    // Expressions
    block: $ => seq('{', repeat($._expression), '}'),
    _expression: $ => choice(
      $.float,
      $.integer,
    ),
    float: _ => /-?\d[\d_]*((e|E)(\+|-)?|\.)[\d_]+/,
    integer: _ => /-?(0x[\da-fA-F_]+|\d[\d_]*)/,

    // Various terminals (e.g. identifiers)
    self: _ => 'self',
    line_comment: _ => token(seq('#', /.*/)),
    identifier: _ => /([a-z]|_)[a-zA-Z\d_]*/,
    field_name: _ => /@[a-zA-Z\d_]+/,
    constant: _ => /[A-Z][a-zA-Z\d_]*/
  }
});
