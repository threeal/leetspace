#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution_c(const std::string& s, int numRows);
std::string solution_cpp(const std::string& s, int numRows);

struct TestCase {
  std::string name;
  std::string s;
  int numRows;
  std::string expected;
};

TEST_CASE("6. Zigzag Conversion") {
  const auto solution = GENERATE(solution_c, solution_cpp);
  const auto [name, s, numRows, expected] = GENERATE(
      TestCase{.name = "Example 1", .s = "PAYPALISHIRING", .numRows = 3, .expected = "PAHNAPLSIIGYIR"},
      TestCase{.name = "Example 2", .s = "PAYPALISHIRING", .numRows = 4, .expected = "PINALSIGYAHRPI"},
      TestCase{.name = "Example 3", .s = "A", .numRows = 1, .expected = "A"});

  INFO("name: " << name);
  INFO("s: " << s);
  INFO("numRows: " << numRows);

  CHECK(solution(s, numRows) == expected);
}
