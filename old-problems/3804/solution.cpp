#include <vector>

class Solution {
 public:
  int centeredSubarrays(std::vector<int>& nums) {
    int count{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      int sum{0};
      for (std::size_t j{i}; j < nums.size(); ++j) {
        sum += nums[j];
        for (std::size_t k{i}; k <= j; ++k) {
          if (sum == nums[k]) {
            ++count;
            break;
          }
        }
      }
    }
    return count;
  }
};
