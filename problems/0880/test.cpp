#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution_c(const std::string& s, int k);
std::string solution_cpp(const std::string& s, int k);

struct TestCase {
  std::string name;
  std::string s;
  int k;
  std::string expected;
};

TEST_CASE("880. Decoded String at Index") {
  const auto solution = GENERATE(solution_c, solution_cpp);
  const auto [name, s, k, expected] = GENERATE(
      TestCase{.name = "Example 1", .s = "leet2code3", .k = 10, .expected = "o"},
      TestCase{.name = "Example 2", .s = "ha22", .k = 5, .expected = "h"},
      TestCase{.name = "Example 3", .s = "a2345678999999999999999", .k = 1, .expected = "a"},
      TestCase{.name = "Index at the end", .s = "a23", .k = 6, .expected = "a"},
      TestCase{.name = "Large string", .s = "czjkk9elaqwiz7s6kgvl4gjixan3ky7jfdg3kyop3husw3fm289thisef8blt7a7zr5v5lhxqpntenvxnmlq7l34ay3jaayikjps", .k = 768077956, .expected = "c"});

  INFO("name: " << name);
  INFO("s: " << s);
  INFO("k: " << k);

  CHECK(solution(s, k) == expected);
}
