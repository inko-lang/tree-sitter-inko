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

  extras: $ => [
    $.comment,
    /\s/,
  ],

  rules: {
    source_file: $ => repeat($._top_level),

    _top_level: $ => choice($.import, alias($.module_method, $.method)),

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

    // TODO: type parameters
    module_method: $ => seq(
      'fn',
      field('name', $.identifier),
      field('arguments', optional(alias($.method_arguments, $.arguments))),
      field('body', $.block),
    ),
    method_arguments: $ => seq('(', comma_list($.argument), ')'),
    argument: $ => seq(
      field('name', $.identifier),
      ':',
      field('type', $._type),
    ),

    // TODO: closure types
    // TODO: Never type
    // TODO: ownership
    _type: $ => choice(
      $.generic_type,
      alias($.constant, $.type),
    ),
    generic_type: $ => seq(
      field('name', $.constant),
      field('arguments', $.type_arguments),
    ),
    type_arguments: $ => seq('[', comma_list($._type), ']'),

    // TODO: add expressions
    block: $ => seq('{', '}'),

    self: _ => 'self',
    comment: _ => token(seq('#', /.*/)),
    identifier: _ => /([a-z]|_)[a-zA-Z0-9_]*/,
    constant: _ => /[A-Z][a-zA-Z0-9_]*/
  }
});
