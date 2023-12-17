#include <catch2/catch_test_macros.hpp>

#include "solution.cpp"

TEST_CASE("2353. Design a Food Rating System (cpp)") {
  SECTION("Example 1") {
    std::vector<std::string> foogs = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    std::vector<std::string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    std::vector<int> ratings = {9, 12, 8, 15, 14, 7};
    FoodRatings foodRatings(foogs, cuisines, ratings);

    REQUIRE(foodRatings.highestRated("korean") == "kimchi");
    REQUIRE(foodRatings.highestRated("japanese") == "ramen");
    foodRatings.changeRating("sushi", 16);
    REQUIRE(foodRatings.highestRated("japanese") == "sushi");
    foodRatings.changeRating("ramen", 16);
    REQUIRE(foodRatings.highestRated("japanese") == "ramen");
  }

  SECTION("Case 1") {
    std::vector<std::string> foogs = {"czopaaeyl", "lxoozsbh", "kbaxapl"};
    std::vector<std::string> cuisines = {"dmnuqeatj", "dmnuqeatj", "dmnuqeatj"};
    std::vector<int> ratings = {11, 2, 15};
    FoodRatings foodRatings(foogs, cuisines, ratings);

    foodRatings.changeRating("czopaaeyl", 12);
    REQUIRE(foodRatings.highestRated("dmnuqeatj") == "kbaxapl");
    foodRatings.changeRating("kbaxapl", 8);
    foodRatings.changeRating("lxoozsbh", 5);
    REQUIRE(foodRatings.highestRated("dmnuqeatj") == "czopaaeyl");
  }
}
