#include <vector>

class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    const int n = nums.size();

    std::vector<int> outputs;
    outputs.reserve(n);

    int i = 0;
    while (i < n && nums[i] < 0) {
      nums[i] *= nums[i];
      ++i;
    }

    int j = i - 1;
    while (i < n) {
      nums[i] *= nums[i];
      while (j >= 0 && nums[j] < nums[i]) {
        outputs.push_back(nums[j]);
        --j;
      }
      outputs.push_back(nums[i]);
      ++i;
    }

    while (j >= 0) {
      outputs.push_back(nums[j]);
      --j;
    }

    return outputs;
  }
};
