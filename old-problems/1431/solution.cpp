#include <vector>

class Solution {
 public:
  std::vector<bool> kidsWithCandies(
      std::vector<int>& candies, int extraCandies) {
    int maxCandy{0};
    for (const int candy : candies) {
      if (candy > maxCandy) maxCandy = candy;
    }

    std::vector<bool> output(candies.size());
    for (std::size_t i{0}; i < candies.size(); ++i) {
      output[i] = candies[i] + extraCandies >= maxCandy;
    }

    return output;
  }
};
