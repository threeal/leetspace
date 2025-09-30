#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxSatisfaction(std::vector<int>& satisfaction) {
    std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());
    int maxSum{0}, sum{0}, diff{0};
    for (const int num : satisfaction) {
      if ((diff += num) < 0) break;
      if ((sum += diff) > maxSum) maxSum = sum;
    }
    return maxSum;
  }
};
