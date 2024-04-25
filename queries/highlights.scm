; Brackets
[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket

; Keywords
[
  ;"as"
  "fn"
  "if"
  ;"or"
  "and"
  "for"
  "let"
  "ref"
  ;"try"
  "mut"
  "uni"
  ;"else"
  "impl"
  ;"loop"
  ;"next"
  ;"move"
  "case"
  "enum"
  "class"
  ;"break"
  ;"match"
  ;"throw"
  "trait"
  ;"while"
  "import"
  ;"return"
  ;"recover"
  (modifier)
  (visibility)
] @keyword

; Comments
(line_comment) @comment

; Literals
[
  (nil)
  (self)
] @keyword

[
  (true)
  (false)
] @boolean

(integer) @number
(float) @number
(string) @string
(escape_sequence) @escape
(interpolation
  "${" @punctuation.special
  "}" @punctuation.special) @embedded

(constant) @constant

; Types
(generic_type name: _ @type)
(type) @type

; Imports
(extern_import path: _ @string)

; Classes
(class name: _ @type)
(field name: _ @property)

; Traits
(trait name: _ @type)

; Implementations
(implement_trait class: _ @type)
(reopen_class name: _ @type)
(bound name: _ @type)
