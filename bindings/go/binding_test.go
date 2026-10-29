package tree_sitter_inko_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_inko "codeberg.org/inko-lang/tree-sitter-inko/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_inko.Language())
	if language == nil {
		t.Errorf("Error loading Inko grammar")
	}
}
