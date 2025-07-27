#include <vector>

class Solution {
 public:
  int countHillValley(std::vector<int>& nums) {
    int count{0};
    bool increasing{false}, decreasing{false};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        if (decreasing) ++count;
        increasing = true;
        decreasing = false;
      } else if (nums[i] < nums[i - 1]) {
        if (increasing) ++count;
        decreasing = true;
        increasing = false;
      }
    }
    return count;
  }
};
