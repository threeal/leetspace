#include <vector>

class Solution {
 public:
  int countSubarrays(std::vector<int>& nums) {
    int count{0};
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if ((nums[i - 2] + nums[i]) * 2 == nums[i - 1]) ++count;
    }
    return count;
  }
};
