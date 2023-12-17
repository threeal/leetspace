#include <string>
#include <vector>

class FoodRatings {
 public:
  FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
    (void)foods;
    (void)cuisines;
    (void)ratings;
  }

  void changeRating(std::string food, int newRating) {
    (void)food;
    (void)newRating;
  }

  std::string highestRated(std::string cuisine) {
    (void)cuisine;
    return "";
  }
};
