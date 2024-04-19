package tree_sitter_inko_test

import (
	"testing"

	"github.com/inko-lang/tree-sitter-inko"
	tree_sitter "github.com/smacker/go-tree-sitter"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_inko.Language())
	if language == nil {
		t.Errorf("Error loading Inko grammar")
	}
}
