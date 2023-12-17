#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

struct FoodRating {
  int rating;
  std::string food;

  bool operator>(const FoodRating& other) const {
    if (rating == other.rating) return food < other.food;
    return rating > other.rating;
  }
};

class FoodRatings {
 private:
  std::unordered_map<std::string, std::set<FoodRating, std::greater<FoodRating>>> cuisine_food_ratings;
  std::unordered_map<std::string, std::string> food_cuisines;
  std::unordered_map<std::string, int> food_ratings;

 public:
  FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
    const auto n = std::min({foods.size(), cuisines.size(), ratings.size()});
    for (std::size_t i = 0; i < n; ++i) {
      cuisine_food_ratings[cuisines[i]].insert({.food = foods[i], .rating = ratings[i]});
      food_cuisines[foods[i]] = cuisines[i];
      food_ratings[foods[i]] = ratings[i];
    }
  }

  void changeRating(std::string food, int newRating) {
    const auto& cuisine = food_cuisines[food];
    const auto rating = food_ratings[food];

    cuisine_food_ratings[cuisine].erase({.food = food, .rating = rating});
    cuisine_food_ratings[cuisine].insert({.food = food, .rating = newRating});

    food_ratings[food] = newRating;
  }

  std::string highestRated(std::string cuisine) {
    return cuisine_food_ratings[cuisine].begin()->food;
    ;
  }
};
