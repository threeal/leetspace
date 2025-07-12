#include <vector>

class Solution {
 public:
  std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
    const int n = nums.size();
    std::vector<int> indices{};
    for (int i{0}; i < n; ++i) {
      if (nums[i] == key) {
        int l{i > k ? i - k : 0};
        if (!indices.empty() && indices.back() + 1 > l) {
          l = indices.back() + 1;
        }

        const int r{i + k < n ? i + k : n - 1};
        while (l <= r) {
          indices.push_back(l);
          ++l;
        }
      }
    }
    return indices;
  }
};
