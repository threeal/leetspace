#include <vector>

class Solution {
 public:
  int numSubarraysWithSum(std::vector<int>& nums, int goal) {
    int sum{0}, zeros{0}, count{0};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      sum += nums[r];
      while (l < r) {
        if (nums[l] == 0) {
          ++zeros;
          ++l;
        } else if (sum > goal) {
          zeros = 0;
          ++l;
          --sum;
        } else {
          break;
        }
      }

      if (sum == goal) count += 1 + zeros;
    }
    return count;
  }
};
