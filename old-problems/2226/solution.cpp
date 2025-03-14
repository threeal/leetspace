#include <vector>

class Solution {
 public:
  int maximumCandies(std::vector<int>& candies, long long k) {
    int low{0}, high{0};
    for (const auto candy : candies) {
      if (candy > high) high = candy;
    }

    while (low < high) {
      const int mid{high - (high - low) / 2};

      long long piles{0};
      if (mid > 0) {
        for (const auto candy : candies) {
          piles += candy / mid;
        }
      }

      if (piles >= k) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};
