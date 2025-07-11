#include <vector>

class Solution {
 public:
  int sumCounts(std::vector<int>& nums) {
    int sum = nums.size();
    for (std::size_t i{0}; i < nums.size(); ++i) {
      bool exists[101]{false};
      exists[nums[i]] = true;

      int distinct{1};
      for (std::size_t j{i + 1}; j < nums.size(); ++j) {
        if (!exists[nums[j]]) {
          exists[nums[j]] = true;
          ++distinct;
        }
        sum += distinct * distinct;
      }
    }
    return sum;
  }
};
