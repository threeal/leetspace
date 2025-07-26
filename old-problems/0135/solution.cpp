#include <vector>

class Solution {
 public:
  int candy(std::vector<int>& ratings) {
    std::vector<int> candies(ratings.size(), 1);
    for (std::size_t i{1}; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }

    int total{candies.back()};
    for (std::size_t i{ratings.size() - 1}; i > 0; --i) {
      if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
        candies[i - 1] = candies[i] + 1;
      }
      total += candies[i - 1];
    }

    return total;
  }
};
