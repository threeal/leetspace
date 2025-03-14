#include <vector>

class Solution {
 public:
  int maximumCandies(std::vector<int>& candies, long long k) {
    return candies.size() + k;
  }
};
