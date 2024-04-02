#include <vector>

class Solution {
 public:
  int majorityElement(std::vector<int>& nums) {
    int num = nums[0];
    int count = 1;
    for (std::size_t i = 1; i < nums.size(); ++i) {
      if (count == 0) {
        num = nums[i];
        count = 1;
      } else {
        if (nums[i] == num)
          ++count;
        else
          --count;
      }
    }
    return num;
  }
};
