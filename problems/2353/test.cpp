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
}
