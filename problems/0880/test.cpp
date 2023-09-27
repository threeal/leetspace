#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution_cpp(const std::string& s, int k);

struct TestCase {
  std::string name;
  std::string s;
  int k;
  std::string expected;
};

TEST_CASE("880. Decoded String at Index") {
  const auto solution = GENERATE(solution_cpp);
  const auto [name, s, k, expected] = GENERATE(
      TestCase{.name = "Example 1", .s = "leet2code3", .k = 10, .expected = "o"},
      TestCase{.name = "Example 2", .s = "ha22", .k = 5, .expected = "h"},
      TestCase{.name = "Example 3", .s = "a2345678999999999999999", .k = 1, .expected = "a"});

  INFO("name: " << name);
  INFO("s: " << s);
  INFO("k: " << k);
  CHECK(solution_cpp(s, k) == expected);
}
