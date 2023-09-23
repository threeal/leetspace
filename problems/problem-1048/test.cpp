#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>
#include <vector>

int solution_cpp(std::vector<std::string>& words);

struct TestCase {
  std::string title;
  std::vector<std::string> words;
  int expected;
};

TEST_CASE("1048. Longest String Chain") {
  auto [title, words, expected] = GENERATE(
      TestCase{
          .title = "Example 1",
          .words = {"a", "b", "ba", "bca", "bda", "bdca"},
          .expected = 4},
      TestCase{
          .title = "Example 2",
          .words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"},
          .expected = 5},
      TestCase{
          .title = "Example 3",
          .words = {"abcd", "dbqca"},
          .expected = 1});

  INFO(title);
  CHECK(solution_cpp(words) == expected);
}
