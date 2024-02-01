#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
    (void)k;

    auto res = std::vector(nums.size() / 3, std::vector<int>(3));
    for (std::size_t i = 0; i < res.size(); ++i) {
      for (std::size_t j = 0; j < 3; ++j) {
        res[i][j] = nums[i * 3 + j];
      }
    }

    return res;
  }
};
