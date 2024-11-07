import XCTest
import SwiftTreeSitter
import TreeSitterInko

final class TreeSitterInkoTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_inko())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Inko grammar")
    }
}
