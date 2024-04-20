#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 95
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 1
#define TOKEN_COUNT 23
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 15

enum ts_symbol_identifiers {
  anon_sym_import = 1,
  anon_sym_DOT = 2,
  anon_sym_LPAREN = 3,
  anon_sym_COMMA = 4,
  anon_sym_RPAREN = 5,
  anon_sym_as = 6,
  anon_sym_if = 7,
  anon_sym_and = 8,
  anon_sym_fn = 9,
  anon_sym_COLON = 10,
  anon_sym_DASH_GT = 11,
  anon_sym_LBRACK = 12,
  anon_sym_RBRACK = 13,
  anon_sym_ref = 14,
  anon_sym_mut = 15,
  anon_sym_uni = 16,
  anon_sym_LBRACE = 17,
  anon_sym_RBRACE = 18,
  sym_self = 19,
  sym_comment = 20,
  sym_identifier = 21,
  sym_constant = 22,
  sym_source_file = 23,
  sym__top_level = 24,
  sym_import = 25,
  sym_path = 26,
  sym_symbols = 27,
  sym__symbol = 28,
  sym_import_as = 29,
  sym_tags = 30,
  sym_module_method = 31,
  sym_method_arguments = 32,
  sym_argument = 33,
  sym__returns = 34,
  sym__type = 35,
  sym_generic_type = 36,
  sym_type_arguments = 37,
  sym_ref_type = 38,
  sym_mut_type = 39,
  sym_uni_type = 40,
  sym_fn_type = 41,
  sym_fn_type_arguments = 42,
  sym_block = 43,
  aux_sym_source_file_repeat1 = 44,
  aux_sym_path_repeat1 = 45,
  aux_sym_symbols_repeat1 = 46,
  aux_sym_tags_repeat1 = 47,
  aux_sym_method_arguments_repeat1 = 48,
  aux_sym_type_arguments_repeat1 = 49,
  alias_sym_type = 50,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_import] = "import",
  [anon_sym_DOT] = ".",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_as] = "as",
  [anon_sym_if] = "if",
  [anon_sym_and] = "and",
  [anon_sym_fn] = "fn",
  [anon_sym_COLON] = ":",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_ref] = "ref",
  [anon_sym_mut] = "mut",
  [anon_sym_uni] = "uni",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_self] = "self",
  [sym_comment] = "comment",
  [sym_identifier] = "identifier",
  [sym_constant] = "constant",
  [sym_source_file] = "source_file",
  [sym__top_level] = "_top_level",
  [sym_import] = "import",
  [sym_path] = "path",
  [sym_symbols] = "symbols",
  [sym__symbol] = "_symbol",
  [sym_import_as] = "import_as",
  [sym_tags] = "tags",
  [sym_module_method] = "method",
  [sym_method_arguments] = "arguments",
  [sym_argument] = "argument",
  [sym__returns] = "_returns",
  [sym__type] = "_type",
  [sym_generic_type] = "generic_type",
  [sym_type_arguments] = "type_arguments",
  [sym_ref_type] = "ref_type",
  [sym_mut_type] = "mut_type",
  [sym_uni_type] = "uni_type",
  [sym_fn_type] = "fn_type",
  [sym_fn_type_arguments] = "arguments",
  [sym_block] = "block",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_path_repeat1] = "path_repeat1",
  [aux_sym_symbols_repeat1] = "symbols_repeat1",
  [aux_sym_tags_repeat1] = "tags_repeat1",
  [aux_sym_method_arguments_repeat1] = "method_arguments_repeat1",
  [aux_sym_type_arguments_repeat1] = "type_arguments_repeat1",
  [alias_sym_type] = "type",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_as] = anon_sym_as,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_ref] = anon_sym_ref,
  [anon_sym_mut] = anon_sym_mut,
  [anon_sym_uni] = anon_sym_uni,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_self] = sym_self,
  [sym_comment] = sym_comment,
  [sym_identifier] = sym_identifier,
  [sym_constant] = sym_constant,
  [sym_source_file] = sym_source_file,
  [sym__top_level] = sym__top_level,
  [sym_import] = sym_import,
  [sym_path] = sym_path,
  [sym_symbols] = sym_symbols,
  [sym__symbol] = sym__symbol,
  [sym_import_as] = sym_import_as,
  [sym_tags] = sym_tags,
  [sym_module_method] = sym_module_method,
  [sym_method_arguments] = sym_method_arguments,
  [sym_argument] = sym_argument,
  [sym__returns] = sym__returns,
  [sym__type] = sym__type,
  [sym_generic_type] = sym_generic_type,
  [sym_type_arguments] = sym_type_arguments,
  [sym_ref_type] = sym_ref_type,
  [sym_mut_type] = sym_mut_type,
  [sym_uni_type] = sym_uni_type,
  [sym_fn_type] = sym_fn_type,
  [sym_fn_type_arguments] = sym_method_arguments,
  [sym_block] = sym_block,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_path_repeat1] = aux_sym_path_repeat1,
  [aux_sym_symbols_repeat1] = aux_sym_symbols_repeat1,
  [aux_sym_tags_repeat1] = aux_sym_tags_repeat1,
  [aux_sym_method_arguments_repeat1] = aux_sym_method_arguments_repeat1,
  [aux_sym_type_arguments_repeat1] = aux_sym_type_arguments_repeat1,
  [alias_sym_type] = alias_sym_type,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_as] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ref] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mut] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uni] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_self] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_constant] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__top_level] = {
    .visible = false,
    .named = true,
  },
  [sym_import] = {
    .visible = true,
    .named = true,
  },
  [sym_path] = {
    .visible = true,
    .named = true,
  },
  [sym_symbols] = {
    .visible = true,
    .named = true,
  },
  [sym__symbol] = {
    .visible = false,
    .named = true,
  },
  [sym_import_as] = {
    .visible = true,
    .named = true,
  },
  [sym_tags] = {
    .visible = true,
    .named = true,
  },
  [sym_module_method] = {
    .visible = true,
    .named = true,
  },
  [sym_method_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_argument] = {
    .visible = true,
    .named = true,
  },
  [sym__returns] = {
    .visible = false,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_generic_type] = {
    .visible = true,
    .named = true,
  },
  [sym_type_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_ref_type] = {
    .visible = true,
    .named = true,
  },
  [sym_mut_type] = {
    .visible = true,
    .named = true,
  },
  [sym_uni_type] = {
    .visible = true,
    .named = true,
  },
  [sym_fn_type] = {
    .visible = true,
    .named = true,
  },
  [sym_fn_type_arguments] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_path_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_symbols_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tags_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_method_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_arguments_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_type] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_alias = 1,
  field_arguments = 2,
  field_body = 3,
  field_name = 4,
  field_path = 5,
  field_returns = 6,
  field_symbols = 7,
  field_tags = 8,
  field_type = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_arguments] = "arguments",
  [field_body] = "body",
  [field_name] = "name",
  [field_path] = "path",
  [field_returns] = "returns",
  [field_symbols] = "symbols",
  [field_tags] = "tags",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 3},
  [6] = {.index = 10, .length = 3},
  [7] = {.index = 13, .length = 3},
  [9] = {.index = 16, .length = 2},
  [10] = {.index = 18, .length = 1},
  [11] = {.index = 19, .length = 1},
  [12] = {.index = 20, .length = 1},
  [13] = {.index = 21, .length = 2},
  [14] = {.index = 23, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_path, 1},
  [1] =
    {field_path, 1},
    {field_symbols, 2},
  [3] =
    {field_path, 1},
    {field_tags, 2},
  [5] =
    {field_body, 2},
    {field_name, 1},
  [7] =
    {field_path, 1},
    {field_symbols, 2},
    {field_tags, 3},
  [10] =
    {field_arguments, 2},
    {field_body, 3},
    {field_name, 1},
  [13] =
    {field_alias, 1},
    {field_alias, 2},
    {field_name, 0},
  [16] =
    {field_name, 0},
    {field_type, 2},
  [18] =
    {field_returns, 1},
  [19] =
    {field_arguments, 1},
  [20] =
    {field_type, 1},
  [21] =
    {field_arguments, 1},
    {field_name, 0},
  [23] =
    {field_arguments, 1},
    {field_returns, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [8] = {
    [0] = alias_sym_type,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(45);
      if (lookahead == '(') ADVANCE(26);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == ',') ADVANCE(27);
      if (lookahead == '-') ADVANCE(3);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == ':') ADVANCE(34);
      if (lookahead == '[') ADVANCE(36);
      if (lookahead == ']') ADVANCE(37);
      if (lookahead == 'a') ADVANCE(12);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(7);
      if (lookahead == 'm') ADVANCE(20);
      if (lookahead == 'r') ADVANCE(5);
      if (lookahead == 's') ADVANCE(6);
      if (lookahead == 'u') ADVANCE(14);
      if (lookahead == '{') ADVANCE(41);
      if (lookahead == '}') ADVANCE(42);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(56);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(45);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'r') ||
          ('t' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      if (lookahead == 's') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(56);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(45);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '>') ADVANCE(35);
      END_STATE();
    case 4:
      if (lookahead == 'd') ADVANCE(31);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == 'f') ADVANCE(30);
      if (lookahead == 'm') ADVANCE(16);
      END_STATE();
    case 8:
      if (lookahead == 'f') ADVANCE(38);
      END_STATE();
    case 9:
      if (lookahead == 'f') ADVANCE(43);
      END_STATE();
    case 10:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(9);
      END_STATE();
    case 12:
      if (lookahead == 'n') ADVANCE(4);
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 14:
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 16:
      if (lookahead == 'p') ADVANCE(15);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 20:
      if (lookahead == 'u') ADVANCE(18);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(45);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'e') ||
          lookahead == 'g' ||
          lookahead == 'h' ||
          ('j' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      if (lookahead == 'f') ADVANCE(50);
      if (lookahead == 'i') ADVANCE(49);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(21)
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_import);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_as);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_fn);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_ref);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_uni);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_self);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_constant);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 21},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_ref] = ACTIONS(1),
    [anon_sym_mut] = ACTIONS(1),
    [anon_sym_uni] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_self] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_constant] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(93),
    [sym__top_level] = STATE(16),
    [sym_import] = STATE(16),
    [sym_module_method] = STATE(16),
    [aux_sym_source_file_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_import] = ACTIONS(7),
    [anon_sym_fn] = ACTIONS(9),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_RBRACK,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    STATE(52), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [30] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    ACTIONS(23), 1,
      anon_sym_RBRACK,
    STATE(52), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [60] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    ACTIONS(25), 1,
      anon_sym_RPAREN,
    STATE(75), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [90] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    ACTIONS(27), 1,
      anon_sym_RBRACK,
    STATE(64), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [120] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    ACTIONS(29), 1,
      anon_sym_RPAREN,
    STATE(52), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [150] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    ACTIONS(31), 1,
      anon_sym_RPAREN,
    STATE(52), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [180] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    STATE(52), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [207] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    STATE(78), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [234] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    STATE(67), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [261] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    STATE(68), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [288] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    STATE(69), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [315] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(15), 1,
      anon_sym_ref,
    ACTIONS(17), 1,
      anon_sym_mut,
    ACTIONS(19), 1,
      anon_sym_uni,
    ACTIONS(21), 1,
      sym_constant,
    STATE(73), 6,
      sym__type,
      sym_generic_type,
      sym_ref_type,
      sym_mut_type,
      sym_uni_type,
      sym_fn_type,
  [342] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_DOT,
    STATE(17), 1,
      aux_sym_path_repeat1,
    ACTIONS(33), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [359] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(41), 1,
      anon_sym_if,
    STATE(26), 1,
      sym_symbols,
    STATE(49), 1,
      sym_tags,
    ACTIONS(37), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [380] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(20), 4,
      sym__top_level,
      sym_import,
      sym_module_method,
      aux_sym_source_file_repeat1,
  [399] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(47), 1,
      anon_sym_DOT,
    STATE(17), 1,
      aux_sym_path_repeat1,
    ACTIONS(45), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [416] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(50), 1,
      anon_sym_LPAREN,
    ACTIONS(54), 1,
      anon_sym_DASH_GT,
    STATE(29), 1,
      sym_fn_type_arguments,
    STATE(65), 1,
      sym__returns,
    ACTIONS(52), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [437] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_DOT,
    STATE(14), 1,
      aux_sym_path_repeat1,
    ACTIONS(56), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [454] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(58), 1,
      ts_builtin_sym_end,
    ACTIONS(60), 1,
      anon_sym_import,
    ACTIONS(63), 1,
      anon_sym_fn,
    STATE(20), 4,
      sym__top_level,
      sym_import,
      sym_module_method,
      aux_sym_source_file_repeat1,
  [473] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(45), 6,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [485] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(66), 1,
      anon_sym_RPAREN,
    ACTIONS(70), 1,
      sym_constant,
    ACTIONS(68), 2,
      sym_self,
      sym_identifier,
    STATE(74), 2,
      sym__symbol,
      sym_import_as,
  [503] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(70), 1,
      sym_constant,
    ACTIONS(72), 1,
      anon_sym_RPAREN,
    ACTIONS(68), 2,
      sym_self,
      sym_identifier,
    STATE(81), 2,
      sym__symbol,
      sym_import_as,
  [521] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(70), 1,
      sym_constant,
    ACTIONS(74), 1,
      anon_sym_RPAREN,
    ACTIONS(68), 2,
      sym_self,
      sym_identifier,
    STATE(81), 2,
      sym__symbol,
      sym_import_as,
  [539] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(78), 1,
      anon_sym_and,
    STATE(25), 1,
      aux_sym_tags_repeat1,
    ACTIONS(76), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [554] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(41), 1,
      anon_sym_if,
    STATE(70), 1,
      sym_tags,
    ACTIONS(81), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [569] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(85), 1,
      anon_sym_and,
    STATE(25), 1,
      aux_sym_tags_repeat1,
    ACTIONS(83), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [584] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(85), 1,
      anon_sym_and,
    STATE(27), 1,
      aux_sym_tags_repeat1,
    ACTIONS(87), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [599] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(54), 1,
      anon_sym_DASH_GT,
    STATE(72), 1,
      sym__returns,
    ACTIONS(89), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [614] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(70), 1,
      sym_constant,
    ACTIONS(68), 2,
      sym_self,
      sym_identifier,
    STATE(81), 2,
      sym__symbol,
      sym_import_as,
  [629] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(93), 1,
      anon_sym_LBRACK,
    STATE(71), 1,
      sym_type_arguments,
    ACTIONS(91), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [644] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [654] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 1,
      anon_sym_LPAREN,
    ACTIONS(99), 1,
      anon_sym_LBRACE,
    STATE(45), 1,
      sym_block,
    STATE(79), 1,
      sym_method_arguments,
  [670] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [680] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 1,
      ts_builtin_sym_end,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(105), 2,
      anon_sym_import,
      anon_sym_fn,
  [694] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(109), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [704] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 1,
      anon_sym_COMMA,
    STATE(37), 1,
      aux_sym_type_arguments_repeat1,
    ACTIONS(114), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [718] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(116), 4,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_RBRACK,
  [728] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(118), 4,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_RBRACK,
  [738] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(120), 4,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_RBRACK,
  [748] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(122), 4,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_DASH_GT,
      anon_sym_RBRACK,
  [758] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(76), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_and,
      anon_sym_fn,
  [768] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(124), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [778] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(128), 1,
      anon_sym_as,
    ACTIONS(126), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [789] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(130), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [798] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(132), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [807] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(134), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [816] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_COMMA,
    ACTIONS(139), 1,
      anon_sym_RPAREN,
    STATE(48), 1,
      aux_sym_symbols_repeat1,
  [829] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(141), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [838] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_RPAREN,
    ACTIONS(145), 1,
      sym_identifier,
    STATE(63), 1,
      sym_argument,
  [851] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 1,
      sym_identifier,
    ACTIONS(147), 1,
      anon_sym_RPAREN,
    STATE(77), 1,
      sym_argument,
  [864] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(114), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [873] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(74), 1,
      anon_sym_RPAREN,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    STATE(48), 1,
      aux_sym_symbols_repeat1,
  [886] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_RBRACK,
    ACTIONS(151), 1,
      anon_sym_COMMA,
    STATE(37), 1,
      aux_sym_type_arguments_repeat1,
  [899] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [908] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_RPAREN,
    ACTIONS(155), 1,
      anon_sym_COMMA,
    STATE(37), 1,
      aux_sym_type_arguments_repeat1,
  [921] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      anon_sym_RPAREN,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    STATE(60), 1,
      aux_sym_method_arguments_repeat1,
  [934] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_as,
    ACTIONS(126), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [945] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 1,
      sym_identifier,
    ACTIONS(161), 1,
      anon_sym_RPAREN,
    STATE(77), 1,
      sym_argument,
  [958] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(163), 1,
      anon_sym_COMMA,
    ACTIONS(166), 1,
      anon_sym_RPAREN,
    STATE(60), 1,
      aux_sym_method_arguments_repeat1,
  [971] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(168), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [980] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(170), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [989] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 1,
      anon_sym_COMMA,
    ACTIONS(174), 1,
      anon_sym_RPAREN,
    STATE(57), 1,
      aux_sym_method_arguments_repeat1,
  [1002] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(176), 1,
      anon_sym_COMMA,
    ACTIONS(178), 1,
      anon_sym_RBRACK,
    STATE(54), 1,
      aux_sym_type_arguments_repeat1,
  [1015] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(180), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1024] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(182), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1033] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(184), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1042] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1051] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(188), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1060] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(190), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [1069] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(192), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1078] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(194), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1087] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(196), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [1096] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(198), 1,
      anon_sym_COMMA,
    ACTIONS(200), 1,
      anon_sym_RPAREN,
    STATE(53), 1,
      aux_sym_symbols_repeat1,
  [1109] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(202), 1,
      anon_sym_COMMA,
    ACTIONS(204), 1,
      anon_sym_RPAREN,
    STATE(56), 1,
      aux_sym_type_arguments_repeat1,
  [1122] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 1,
      sym_identifier,
    STATE(77), 1,
      sym_argument,
  [1132] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(166), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1140] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(206), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1148] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 1,
      anon_sym_LBRACE,
    STATE(61), 1,
      sym_block,
  [1158] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(208), 1,
      sym_identifier,
    STATE(15), 1,
      sym_path,
  [1168] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1176] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(210), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1184] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(212), 1,
      anon_sym_LBRACE,
  [1191] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(214), 1,
      anon_sym_LBRACE,
  [1198] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(216), 1,
      anon_sym_COLON,
  [1205] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 1,
      anon_sym_LBRACE,
  [1212] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(220), 1,
      sym_identifier,
  [1219] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(220), 1,
      sym_constant,
  [1226] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(222), 1,
      anon_sym_RBRACE,
  [1233] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 1,
      sym_identifier,
  [1240] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(226), 1,
      anon_sym_LBRACE,
  [1247] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym_identifier,
  [1254] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      ts_builtin_sym_end,
  [1261] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(232), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 30,
  [SMALL_STATE(4)] = 60,
  [SMALL_STATE(5)] = 90,
  [SMALL_STATE(6)] = 120,
  [SMALL_STATE(7)] = 150,
  [SMALL_STATE(8)] = 180,
  [SMALL_STATE(9)] = 207,
  [SMALL_STATE(10)] = 234,
  [SMALL_STATE(11)] = 261,
  [SMALL_STATE(12)] = 288,
  [SMALL_STATE(13)] = 315,
  [SMALL_STATE(14)] = 342,
  [SMALL_STATE(15)] = 359,
  [SMALL_STATE(16)] = 380,
  [SMALL_STATE(17)] = 399,
  [SMALL_STATE(18)] = 416,
  [SMALL_STATE(19)] = 437,
  [SMALL_STATE(20)] = 454,
  [SMALL_STATE(21)] = 473,
  [SMALL_STATE(22)] = 485,
  [SMALL_STATE(23)] = 503,
  [SMALL_STATE(24)] = 521,
  [SMALL_STATE(25)] = 539,
  [SMALL_STATE(26)] = 554,
  [SMALL_STATE(27)] = 569,
  [SMALL_STATE(28)] = 584,
  [SMALL_STATE(29)] = 599,
  [SMALL_STATE(30)] = 614,
  [SMALL_STATE(31)] = 629,
  [SMALL_STATE(32)] = 644,
  [SMALL_STATE(33)] = 654,
  [SMALL_STATE(34)] = 670,
  [SMALL_STATE(35)] = 680,
  [SMALL_STATE(36)] = 694,
  [SMALL_STATE(37)] = 704,
  [SMALL_STATE(38)] = 718,
  [SMALL_STATE(39)] = 728,
  [SMALL_STATE(40)] = 738,
  [SMALL_STATE(41)] = 748,
  [SMALL_STATE(42)] = 758,
  [SMALL_STATE(43)] = 768,
  [SMALL_STATE(44)] = 778,
  [SMALL_STATE(45)] = 789,
  [SMALL_STATE(46)] = 798,
  [SMALL_STATE(47)] = 807,
  [SMALL_STATE(48)] = 816,
  [SMALL_STATE(49)] = 829,
  [SMALL_STATE(50)] = 838,
  [SMALL_STATE(51)] = 851,
  [SMALL_STATE(52)] = 864,
  [SMALL_STATE(53)] = 873,
  [SMALL_STATE(54)] = 886,
  [SMALL_STATE(55)] = 899,
  [SMALL_STATE(56)] = 908,
  [SMALL_STATE(57)] = 921,
  [SMALL_STATE(58)] = 934,
  [SMALL_STATE(59)] = 945,
  [SMALL_STATE(60)] = 958,
  [SMALL_STATE(61)] = 971,
  [SMALL_STATE(62)] = 980,
  [SMALL_STATE(63)] = 989,
  [SMALL_STATE(64)] = 1002,
  [SMALL_STATE(65)] = 1015,
  [SMALL_STATE(66)] = 1024,
  [SMALL_STATE(67)] = 1033,
  [SMALL_STATE(68)] = 1042,
  [SMALL_STATE(69)] = 1051,
  [SMALL_STATE(70)] = 1060,
  [SMALL_STATE(71)] = 1069,
  [SMALL_STATE(72)] = 1078,
  [SMALL_STATE(73)] = 1087,
  [SMALL_STATE(74)] = 1096,
  [SMALL_STATE(75)] = 1109,
  [SMALL_STATE(76)] = 1122,
  [SMALL_STATE(77)] = 1132,
  [SMALL_STATE(78)] = 1140,
  [SMALL_STATE(79)] = 1148,
  [SMALL_STATE(80)] = 1158,
  [SMALL_STATE(81)] = 1168,
  [SMALL_STATE(82)] = 1176,
  [SMALL_STATE(83)] = 1184,
  [SMALL_STATE(84)] = 1191,
  [SMALL_STATE(85)] = 1198,
  [SMALL_STATE(86)] = 1205,
  [SMALL_STATE(87)] = 1212,
  [SMALL_STATE(88)] = 1219,
  [SMALL_STATE(89)] = 1226,
  [SMALL_STATE(90)] = 1233,
  [SMALL_STATE(91)] = 1240,
  [SMALL_STATE(92)] = 1247,
  [SMALL_STATE(93)] = 1254,
  [SMALL_STATE(94)] = 1261,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 2, .production_id = 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(92),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(80),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(94),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tags_repeat1, 2),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tags_repeat1, 2), SHIFT_REPEAT(90),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 3, .production_id = 2),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 3),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 2),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type, 2, .production_id = 11),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 1, .production_id = 8),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 1),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tags, 1),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 3),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_arguments_repeat1, 2), SHIFT_REPEAT(8),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_arguments_repeat1, 2),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type_arguments, 2),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type_arguments, 5),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type_arguments, 3),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type_arguments, 4),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 4),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__symbol, 1),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_method, 3, .production_id = 4),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 5),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 4),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_symbols_repeat1, 2), SHIFT_REPEAT(30),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_symbols_repeat1, 2),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 3, .production_id = 3),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 3),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [163] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_arguments_repeat1, 2), SHIFT_REPEAT(76),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_method_arguments_repeat1, 2),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_method, 4, .production_id = 6),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type, 2, .production_id = 10),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 2),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref_type, 2, .production_id = 12),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_type, 2, .production_id = 12),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uni_type, 2, .production_id = 12),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 4, .production_id = 5),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 2, .production_id = 13),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_type, 3, .production_id = 14),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__returns, 2),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument, 3, .production_id = 9),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_as, 3, .production_id = 7),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 5),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 2),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 4),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 3),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [230] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_inko() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
