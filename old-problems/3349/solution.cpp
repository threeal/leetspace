#include <vector>

class Solution {
 public:
  bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
    const std::size_t kk = k;
    bool prevIncreasing{false};
    std::size_t l{0};
    for (std::size_t r{1}; r < nums.size(); ++r) {
      if (nums[r] <= nums[r - 1]) {
        if (r - l >= kk) {
          if (prevIncreasing || r - l >= kk * 2) {
            return true;
          } else {
            prevIncreasing = true;
          }
        } else {
          prevIncreasing = false;
        }
        l = r;
      }
    }
    return prevIncreasing ? nums.size() - l >= kk : nums.size() - l >= kk * 2;
  }
};
