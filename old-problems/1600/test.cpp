// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1600. Throne Inheritance") {
  SECTION("Example 1") {
    ThroneInheritance inheritance("king");
    inheritance.birth("king", "andy");
    inheritance.birth("king", "bob");
    inheritance.birth("king", "catherine");
    inheritance.birth("andy", "matthew");
    inheritance.birth("bob", "alex");
    inheritance.birth("bob", "asha");

    REQUIRE(inheritance.getInheritanceOrder() == std::vector<std::string>{"king", "andy", "matthew", "bob", "alex", "asha", "catherine"});

    inheritance.death("bob");

    REQUIRE(inheritance.getInheritanceOrder() == std::vector<std::string>{"king", "andy", "matthew", "alex", "asha", "catherine"});
  }

  SECTION("Test Case 3") {
    ThroneInheritance inheritance("king");
    inheritance.birth("king", "clyde");

    REQUIRE(inheritance.getInheritanceOrder() == std::vector<std::string>{"king", "clyde"});

    inheritance.death("clyde");
    inheritance.birth("king", "shannon");

    REQUIRE(inheritance.getInheritanceOrder() == std::vector<std::string>{"king", "shannon"});

    inheritance.birth("king", "scott");
    inheritance.birth("scott", "keith");

    REQUIRE(inheritance.getInheritanceOrder() == std::vector<std::string>{"king", "shannon", "scott", "keith"});
  }
}
