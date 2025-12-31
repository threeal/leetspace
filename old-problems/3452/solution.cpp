#include <vector>

class Solution {
 public:
  int sumOfGoodNumbers(std::vector<int>& nums, int k) {
    int sum{0};
    const int n = nums.size();
    for (int i{0}; i < n; ++i) {
      if ((i - k < 0 || nums[i] > nums[i - k]) &&
          (i + k >= n || nums[i] > nums[i + k])) {
        sum += nums[i];
      }
    }
    return sum;
  }
};
