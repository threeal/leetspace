#include <vector>

class Solution {
 public:
  std::vector<int> resultsArray(std::vector<int>& nums, int k) {
    if (--k == 0) return nums;

    int count{0};
    for (int i{1}; i < k; ++i) {
      if (nums[i - 1] + 1 == nums[i]) {
        ++count;
      } else {
        count = 0;
      }
    }

    std::vector<int> output(nums.size() - k);
    for (std::size_t i = k; i < nums.size(); ++i) {
      if (nums[i - 1] + 1 == nums[i]) {
        output[i - k] = ++count >= k ? nums[i] : -1;
      } else {
        count = 0;
        output[i - k] = -1;
      }
    }

    return output;
  }
};
