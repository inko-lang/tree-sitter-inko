#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 74
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 40
#define ALIAS_COUNT 1
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 8
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 11

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
  anon_sym_LBRACK = 11,
  anon_sym_RBRACK = 12,
  anon_sym_LBRACE = 13,
  anon_sym_RBRACE = 14,
  sym_self = 15,
  sym_comment = 16,
  sym_identifier = 17,
  sym_constant = 18,
  sym_source_file = 19,
  sym__top_level = 20,
  sym_import = 21,
  sym_path = 22,
  sym_symbols = 23,
  sym__symbol = 24,
  sym_import_as = 25,
  sym_tags = 26,
  sym_module_method = 27,
  sym_method_arguments = 28,
  sym_argument = 29,
  sym__type = 30,
  sym_generic_type = 31,
  sym_type_arguments = 32,
  sym_block = 33,
  aux_sym_source_file_repeat1 = 34,
  aux_sym_path_repeat1 = 35,
  aux_sym_symbols_repeat1 = 36,
  aux_sym_tags_repeat1 = 37,
  aux_sym_method_arguments_repeat1 = 38,
  aux_sym_type_arguments_repeat1 = 39,
  alias_sym_type = 40,
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
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
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
  [sym__type] = "_type",
  [sym_generic_type] = "generic_type",
  [sym_type_arguments] = "type_arguments",
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
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
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
  [sym__type] = sym__type,
  [sym_generic_type] = sym_generic_type,
  [sym_type_arguments] = sym_type_arguments,
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
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
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
  field_symbols = 6,
  field_tags = 7,
  field_type = 8,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_arguments] = "arguments",
  [field_body] = "body",
  [field_name] = "name",
  [field_path] = "path",
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
  [10] = {.index = 18, .length = 2},
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
    {field_arguments, 1},
    {field_name, 0},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(15);
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == ',') ADVANCE(20);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == ':') ADVANCE(27);
      if (lookahead == '[') ADVANCE(28);
      if (lookahead == ']') ADVANCE(29);
      if (lookahead == 'a') ADVANCE(8);
      if (lookahead == 'f') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == 's') ADVANCE(4);
      if (lookahead == '{') ADVANCE(30);
      if (lookahead == '}') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(45);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'r') ||
          ('t' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      if (lookahead == 's') ADVANCE(35);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(45);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == 'd') ADVANCE(24);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 5:
      if (lookahead == 'f') ADVANCE(23);
      if (lookahead == 'm') ADVANCE(11);
      END_STATE();
    case 6:
      if (lookahead == 'f') ADVANCE(32);
      END_STATE();
    case 7:
      if (lookahead == 'l') ADVANCE(6);
      END_STATE();
    case 8:
      if (lookahead == 'n') ADVANCE(3);
      if (lookahead == 's') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == 'p') ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(16);
      END_STATE();
    case 14:
      if (eof) ADVANCE(15);
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'e') ||
          lookahead == 'g' ||
          lookahead == 'h' ||
          ('j' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'i') ADVANCE(38);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14)
      END_STATE();
    case 15:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_import);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_as);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_fn);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_self);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_self);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_constant);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
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
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 14},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 2},
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
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_self] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_constant] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(72),
    [sym__top_level] = STATE(5),
    [sym_import] = STATE(5),
    [sym_module_method] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_import] = ACTIONS(7),
    [anon_sym_fn] = ACTIONS(9),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_DOT,
    STATE(2), 1,
      aux_sym_path_repeat1,
    ACTIONS(11), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [17] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(16), 1,
      ts_builtin_sym_end,
    ACTIONS(18), 1,
      anon_sym_import,
    ACTIONS(21), 1,
      anon_sym_fn,
    STATE(3), 4,
      sym__top_level,
      sym_import,
      sym_module_method,
      aux_sym_source_file_repeat1,
  [36] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(26), 1,
      anon_sym_DOT,
    STATE(2), 1,
      aux_sym_path_repeat1,
    ACTIONS(24), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [53] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(28), 1,
      ts_builtin_sym_end,
    STATE(3), 4,
      sym__top_level,
      sym_import,
      sym_module_method,
      aux_sym_source_file_repeat1,
  [72] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(26), 1,
      anon_sym_DOT,
    STATE(4), 1,
      aux_sym_path_repeat1,
    ACTIONS(30), 5,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [89] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(34), 1,
      anon_sym_LPAREN,
    ACTIONS(36), 1,
      anon_sym_if,
    STATE(15), 1,
      sym_symbols,
    STATE(50), 1,
      sym_tags,
    ACTIONS(32), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [110] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(38), 1,
      anon_sym_RPAREN,
    ACTIONS(42), 1,
      sym_constant,
    ACTIONS(40), 2,
      sym_self,
      sym_identifier,
    STATE(56), 2,
      sym__symbol,
      sym_import_as,
  [128] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(42), 1,
      sym_constant,
    ACTIONS(44), 1,
      anon_sym_RPAREN,
    ACTIONS(40), 2,
      sym_self,
      sym_identifier,
    STATE(28), 2,
      sym__symbol,
      sym_import_as,
  [146] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(11), 6,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_if,
      anon_sym_fn,
  [158] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(42), 1,
      sym_constant,
    ACTIONS(46), 1,
      anon_sym_RPAREN,
    ACTIONS(40), 2,
      sym_self,
      sym_identifier,
    STATE(56), 2,
      sym__symbol,
      sym_import_as,
  [176] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(42), 1,
      sym_constant,
    ACTIONS(40), 2,
      sym_self,
      sym_identifier,
    STATE(56), 2,
      sym__symbol,
      sym_import_as,
  [191] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(50), 1,
      anon_sym_and,
    STATE(14), 1,
      aux_sym_tags_repeat1,
    ACTIONS(48), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [206] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(54), 1,
      anon_sym_and,
    STATE(14), 1,
      aux_sym_tags_repeat1,
    ACTIONS(52), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [221] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(36), 1,
      anon_sym_if,
    STATE(33), 1,
      sym_tags,
    ACTIONS(57), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [236] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    STATE(53), 1,
      sym_type_arguments,
    ACTIONS(59), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [251] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(50), 1,
      anon_sym_and,
    STATE(13), 1,
      aux_sym_tags_repeat1,
    ACTIONS(63), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [266] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      anon_sym_LPAREN,
    ACTIONS(67), 1,
      anon_sym_LBRACE,
    STATE(45), 1,
      sym_block,
    STATE(54), 1,
      sym_method_arguments,
  [282] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(69), 1,
      anon_sym_RBRACK,
    ACTIONS(71), 1,
      sym_constant,
    STATE(61), 2,
      sym__type,
      sym_generic_type,
  [296] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(73), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [306] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    ACTIONS(79), 1,
      sym_identifier,
    ACTIONS(77), 2,
      anon_sym_import,
      anon_sym_fn,
  [320] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(52), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_and,
      anon_sym_fn,
  [330] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(71), 1,
      sym_constant,
    ACTIONS(81), 1,
      anon_sym_RBRACK,
    STATE(34), 2,
      sym__type,
      sym_generic_type,
  [344] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(83), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [354] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(85), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [364] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 4,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_if,
      anon_sym_fn,
  [374] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(71), 1,
      sym_constant,
    ACTIONS(89), 1,
      anon_sym_RBRACK,
    STATE(61), 2,
      sym__type,
      sym_generic_type,
  [388] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 1,
      anon_sym_COMMA,
    ACTIONS(93), 1,
      anon_sym_RPAREN,
    STATE(37), 1,
      aux_sym_symbols_repeat1,
  [401] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [410] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 1,
      anon_sym_COMMA,
    ACTIONS(99), 1,
      anon_sym_RPAREN,
    STATE(41), 1,
      aux_sym_method_arguments_repeat1,
  [423] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [432] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [441] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(105), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [450] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 1,
      anon_sym_COMMA,
    ACTIONS(109), 1,
      anon_sym_RBRACK,
    STATE(35), 1,
      aux_sym_type_arguments_repeat1,
  [463] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_RBRACK,
    ACTIONS(111), 1,
      anon_sym_COMMA,
    STATE(51), 1,
      aux_sym_type_arguments_repeat1,
  [476] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(71), 1,
      sym_constant,
    STATE(61), 2,
      sym__type,
      sym_generic_type,
  [487] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(38), 1,
      anon_sym_RPAREN,
    ACTIONS(113), 1,
      anon_sym_COMMA,
    STATE(44), 1,
      aux_sym_symbols_repeat1,
  [500] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [509] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(71), 1,
      sym_constant,
    STATE(57), 2,
      sym__type,
      sym_generic_type,
  [520] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_RPAREN,
    ACTIONS(119), 1,
      sym_identifier,
    STATE(59), 1,
      sym_argument,
  [533] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_RPAREN,
    ACTIONS(121), 1,
      anon_sym_COMMA,
    STATE(49), 1,
      aux_sym_method_arguments_repeat1,
  [546] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 1,
      anon_sym_as,
    ACTIONS(123), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [557] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      anon_sym_as,
    ACTIONS(123), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [568] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(129), 1,
      anon_sym_COMMA,
    ACTIONS(132), 1,
      anon_sym_RPAREN,
    STATE(44), 1,
      aux_sym_symbols_repeat1,
  [581] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(134), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [590] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [599] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      sym_identifier,
    ACTIONS(138), 1,
      anon_sym_RPAREN,
    STATE(30), 1,
      sym_argument,
  [612] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      sym_identifier,
    ACTIONS(140), 1,
      anon_sym_RPAREN,
    STATE(59), 1,
      sym_argument,
  [625] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(145), 1,
      anon_sym_RPAREN,
    STATE(49), 1,
      aux_sym_method_arguments_repeat1,
  [638] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_fn,
  [647] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    ACTIONS(152), 1,
      anon_sym_RBRACK,
    STATE(51), 1,
      aux_sym_type_arguments_repeat1,
  [660] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(154), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [669] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(156), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [678] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(67), 1,
      anon_sym_LBRACE,
    STATE(32), 1,
      sym_block,
  [688] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [696] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(132), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [704] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(160), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [712] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      sym_identifier,
    STATE(59), 1,
      sym_argument,
  [722] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [730] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(162), 1,
      sym_identifier,
    STATE(7), 1,
      sym_path,
  [740] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(152), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [748] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(164), 1,
      anon_sym_LBRACE,
  [755] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(166), 1,
      sym_identifier,
  [762] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(168), 1,
      anon_sym_LBRACE,
  [769] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(170), 1,
      anon_sym_LBRACE,
  [776] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 1,
      sym_constant,
  [783] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 1,
      sym_identifier,
  [790] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(174), 1,
      anon_sym_COLON,
  [797] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(176), 1,
      anon_sym_LBRACE,
  [804] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_RBRACE,
  [811] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(180), 1,
      sym_identifier,
  [818] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(182), 1,
      ts_builtin_sym_end,
  [825] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(184), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 17,
  [SMALL_STATE(4)] = 36,
  [SMALL_STATE(5)] = 53,
  [SMALL_STATE(6)] = 72,
  [SMALL_STATE(7)] = 89,
  [SMALL_STATE(8)] = 110,
  [SMALL_STATE(9)] = 128,
  [SMALL_STATE(10)] = 146,
  [SMALL_STATE(11)] = 158,
  [SMALL_STATE(12)] = 176,
  [SMALL_STATE(13)] = 191,
  [SMALL_STATE(14)] = 206,
  [SMALL_STATE(15)] = 221,
  [SMALL_STATE(16)] = 236,
  [SMALL_STATE(17)] = 251,
  [SMALL_STATE(18)] = 266,
  [SMALL_STATE(19)] = 282,
  [SMALL_STATE(20)] = 296,
  [SMALL_STATE(21)] = 306,
  [SMALL_STATE(22)] = 320,
  [SMALL_STATE(23)] = 330,
  [SMALL_STATE(24)] = 344,
  [SMALL_STATE(25)] = 354,
  [SMALL_STATE(26)] = 364,
  [SMALL_STATE(27)] = 374,
  [SMALL_STATE(28)] = 388,
  [SMALL_STATE(29)] = 401,
  [SMALL_STATE(30)] = 410,
  [SMALL_STATE(31)] = 423,
  [SMALL_STATE(32)] = 432,
  [SMALL_STATE(33)] = 441,
  [SMALL_STATE(34)] = 450,
  [SMALL_STATE(35)] = 463,
  [SMALL_STATE(36)] = 476,
  [SMALL_STATE(37)] = 487,
  [SMALL_STATE(38)] = 500,
  [SMALL_STATE(39)] = 509,
  [SMALL_STATE(40)] = 520,
  [SMALL_STATE(41)] = 533,
  [SMALL_STATE(42)] = 546,
  [SMALL_STATE(43)] = 557,
  [SMALL_STATE(44)] = 568,
  [SMALL_STATE(45)] = 581,
  [SMALL_STATE(46)] = 590,
  [SMALL_STATE(47)] = 599,
  [SMALL_STATE(48)] = 612,
  [SMALL_STATE(49)] = 625,
  [SMALL_STATE(50)] = 638,
  [SMALL_STATE(51)] = 647,
  [SMALL_STATE(52)] = 660,
  [SMALL_STATE(53)] = 669,
  [SMALL_STATE(54)] = 678,
  [SMALL_STATE(55)] = 688,
  [SMALL_STATE(56)] = 696,
  [SMALL_STATE(57)] = 704,
  [SMALL_STATE(58)] = 712,
  [SMALL_STATE(59)] = 722,
  [SMALL_STATE(60)] = 730,
  [SMALL_STATE(61)] = 740,
  [SMALL_STATE(62)] = 748,
  [SMALL_STATE(63)] = 755,
  [SMALL_STATE(64)] = 762,
  [SMALL_STATE(65)] = 769,
  [SMALL_STATE(66)] = 776,
  [SMALL_STATE(67)] = 783,
  [SMALL_STATE(68)] = 790,
  [SMALL_STATE(69)] = 797,
  [SMALL_STATE(70)] = 804,
  [SMALL_STATE(71)] = 811,
  [SMALL_STATE(72)] = 818,
  [SMALL_STATE(73)] = 825,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_path_repeat1, 2), SHIFT_REPEAT(71),
  [16] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(60),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(73),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 2),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_path, 1),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 2, .production_id = 1),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 3),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tags_repeat1, 2),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tags_repeat1, 2), SHIFT_REPEAT(63),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 3, .production_id = 2),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 1, .production_id = 8),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 2),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 5),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tags, 1),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tags, 1),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 4),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_symbols, 3),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 3),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_method, 4, .production_id = 6),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 4, .production_id = 5),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__symbol, 1),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_symbols_repeat1, 2), SHIFT_REPEAT(12),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_symbols_repeat1, 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_method, 3, .production_id = 4),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 4),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_method_arguments_repeat1, 2), SHIFT_REPEAT(58),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_method_arguments_repeat1, 2),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import, 3, .production_id = 3),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_arguments_repeat1, 2), SHIFT_REPEAT(36),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_arguments_repeat1, 2),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_arguments, 5),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_type, 2, .production_id = 10),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_as, 3, .production_id = 7),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument, 3, .production_id = 9),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 3),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 4),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 5),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_arguments, 2),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [182] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
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
