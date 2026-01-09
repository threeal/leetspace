// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("208. Implement Trie (Prefix Tree)") {
  SECTION("Example 1") {
    Trie trie{};
    trie.insert("apple");
    REQUIRE(trie.search("apple"));
    REQUIRE_FALSE(trie.search("app"));
    REQUIRE(trie.startsWith("app"));
    trie.insert("app");
    REQUIRE(trie.search("app"));
  }
}
