#include <vector>

int pown(int x, int n) {
  int result{1};
  while (n) {
    if (n & 1) result *= x;
    x *= x;
    n >>= 1;
  }
  return result;
}

class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> subsets{{}};
    subsets.reserve(pown(2, nums.size() - 1));
    for (std::size_t i{0}; i < nums.size(); ++i) {
      const std::size_t n{subsets.size()};
      for (std::size_t j{0}; j < n; ++j) {
        subsets.push_back(subsets[j]);
        subsets.back().push_back(nums[i]);
      }
    }

    return subsets;
  }
};
