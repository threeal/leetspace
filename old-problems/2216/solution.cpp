#include <vector>

class Solution {
 public:
  int minDeletion(std::vector<int>& nums) {
    int deletion{};
    for (std::size_t i{1}; i < nums.size(); i += 2) {
      while (i < nums.size() && nums[i - 1] == nums[i]) {
        ++deletion;
        ++i;
      }
    }
    if ((nums.size() - deletion) % 2 != 0) ++deletion;
    return deletion;
  }
};
