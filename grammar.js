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
    $.comment,
    /\s/,
  ],

  rules: {
    source_file: $ => repeat($._top_level),
    _top_level: $ => choice(
      $.import,
      $.external_function,
      $.module_method,
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

    // Methods
    external_function: $ => seq(
      'fn',
      field('visibility', optional($.public)),
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
      field('visibility', optional($.public)),
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
    public: _ => 'pub',

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

    // TODO: add expressions
    block: $ => seq('{', '}'),

    // Various terminals (e.g. identifiers)
    self: _ => 'self',
    comment: _ => token(seq('#', /.*/)),
    identifier: _ => /([a-z]|_)[a-zA-Z0-9_]*/,
    constant: _ => /[A-Z][a-zA-Z0-9_]*/
  }
});
