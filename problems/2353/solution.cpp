#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

struct Cuisine;

struct Food {
  std::string name;
  Cuisine* cuisine;
  int rating;

  Food(const std::string& name, int rating) : name(name), rating(rating) {}
};

struct FoodRating {
  Food* food;
  bool operator>(const FoodRating& other) const {
    if (food->rating == other.food->rating) return food->name < other.food->name;
    return food->rating > other.food->rating;
  }
};

struct Cuisine {
  std::set<FoodRating, std::greater<FoodRating>> foodRatings;
};

class FoodRatings {
 private:
  std::unordered_map<std::string, std::shared_ptr<Food>> food_map;
  std::unordered_map<std::string, std::shared_ptr<Cuisine>> cuisine_map;

 public:
  FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
    const auto n = std::min({foods.size(), cuisines.size(), ratings.size()});
    for (std::size_t i = 0; i < n; ++i) {
      auto food = std::make_shared<Food>(foods[i], ratings[i]);
      food_map[foods[i]] = food;

      auto cuisine_it = cuisine_map.find(cuisines[i]);
      if (cuisine_it == cuisine_map.end()) {
        cuisine_it = cuisine_map.emplace(cuisines[i], std::make_shared<Cuisine>()).first;
      }

      cuisine_it->second->foodRatings.insert({.food = food.get()});
      food->cuisine = cuisine_it->second.get();
    }
  }

  void changeRating(std::string food_name, int new_rating) {
    auto food = food_map[food_name];
    food->cuisine->foodRatings.erase({.food = food.get()});
    food->rating = new_rating;
    food->cuisine->foodRatings.insert({.food = food.get()});
  }

  std::string highestRated(std::string cuisine) {
    return cuisine_map[cuisine]->foodRatings.begin()->food->name;
  }
};
