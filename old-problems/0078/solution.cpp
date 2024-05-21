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
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = subsets.size() - 1; j >= 0; --j) {
        subsets.push_back(subsets[j]);
        subsets.back().push_back(nums[i]);
      }
    }

    return subsets;
  }
};
