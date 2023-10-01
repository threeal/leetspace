#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution(const std::string& s) {
  return s;
}

struct TestCase {
  std::string name;
  std::string s;
  std::string expected;
};

TEST_CASE("557. Reverse Words in a String III") {
  const auto [name, s, expected] = GENERATE(
      TestCase{.name = "Example 1", .s = "Let's take LeetCode contest", .expected = "s'teL ekat edoCteeL tsetnoc"},
      TestCase{.name = "Example 2", .s = "God Ding", .expected = "doG gniD"});

  CAPTURE(name, s);
  CHECK(solution(s) == expected);
}
