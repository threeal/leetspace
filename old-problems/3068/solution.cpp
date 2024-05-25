#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& /*edges*/) {
    long long total{0};
    int gainCount{0};
    int minGain{std::numeric_limits<int>::max()};
    int minLoss{std::numeric_limits<int>::min()};
    for (const auto num : nums) {
      total += num;
      const int gain{(num ^ k) - num};
      if (gain > 0) {
        total += gain;
        ++gainCount;
        if (gain < minGain) minGain = gain;
      } else {
        if (gain > minLoss) minLoss = gain;
      }
    }
    if (gainCount % 2 == 1) {
      total -= minLoss != std::numeric_limits<int>::min()
          ? std::min(minGain, -minLoss)
          : minGain;
    }
    return total;
  }
};
