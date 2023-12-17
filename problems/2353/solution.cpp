#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class FoodRatings {
 private:
  std::unordered_map<std::string, std::string> cuisines_best_foods;
  std::unordered_map<std::string, std::string> food_cuisines;
  std::unordered_map<std::string, int> food_ratings;

 public:
  FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
    const auto n = std::min({foods.size(), cuisines.size(), ratings.size()});
    for (std::size_t i = 0; i < n; ++i) {
      food_cuisines[foods[i]] = cuisines[i];
      changeRating(foods[i], ratings[i]);
    }
  }

  void changeRating(std::string food, int newRating) {
    food_ratings[food] = newRating;
    const auto& cuisine = food_cuisines[food];
    const auto& best_food = cuisines_best_foods[cuisine];
    if (best_food != food) {
      const auto rating = food_ratings[best_food];
      if (newRating > rating || (newRating == rating && food.compare(best_food) < 0)) {
        cuisines_best_foods[cuisine] = food;
      }
    }
  }

  std::string highestRated(std::string cuisine) {
    return cuisines_best_foods[cuisine];
  }
};
