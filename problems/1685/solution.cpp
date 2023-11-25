#include <cmath>
#include <vector>

class Solution {
 public:
  std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
    std::vector<int> res(nums.size(), 0);

    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = i + 1; j < nums.size(); ++j) {
        const int diff = std::abs(nums[j] - nums[i]);
        res[i] += diff;
        res[j] += diff;
      }
    }

    return res;
  }
};
