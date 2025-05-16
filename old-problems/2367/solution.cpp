#include <vector>

class Solution {
 public:
  int arithmeticTriplets(std::vector<int>& nums, int diff) {
    int count{0};
    for (std::size_t i{0}, j{1}, k{2}; k < nums.size(); ++k) {
      while (j < k && nums[j] + diff < nums[k]) ++j;
      while (i < j && nums[i] + diff < nums[j]) ++i;
      if (nums[i] + diff == nums[j] && nums[j] + diff == nums[k]) ++count;
    }
    return count;
  }
};
