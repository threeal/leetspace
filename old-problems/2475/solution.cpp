#include <vector>

class Solution {
 public:
  int unequalTriplets(std::vector<int>& nums) {
    int count{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      for (std::size_t j{i + 1}; j < nums.size(); ++j) {
        if (nums[i] == nums[j]) continue;
        for (std::size_t k{j + 1}; k < nums.size(); ++k) {
          if (nums[i] != nums[k] && nums[j] != nums[k]) ++count;
        }
      }
    }
    return count;
  }
};
