#include <vector>

class Solution {
 public:
  int maximumSum(std::vector<int>& nums) {
    int max{-1};
    int maxOfSum[82] = {0};
    for (auto num : nums) {
      int sum{0};
      for (int n{num}; n > 0; n /= 10) sum += n % 10;
      if (maxOfSum[sum] > 0 && maxOfSum[sum] + num > max) {
        max = maxOfSum[sum] + num;
      }
      if (num > maxOfSum[sum]) maxOfSum[sum] = num;
    }
    return max;
  }
};
