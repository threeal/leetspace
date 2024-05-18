#include <algorithm>
#include <vector>

class Solution {
 public:
  long long maximumHappinessSum(std::vector<int>& happiness, int k) {
    std::sort(happiness.begin(), happiness.end(), std::greater<int>());

    long long sum{0};
    for (int i{0}; i < k; ++i) {
      if (happiness[i] <= i) break;
      sum += happiness[i] - i;
    }

    return sum;
  }
};
