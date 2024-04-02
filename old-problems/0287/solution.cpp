#include <vector>

class Solution {
 public:
  int findDuplicate(std::vector<int>& nums) {
    auto slow = nums[nums[0]];
    auto fast = nums[nums[nums[0]]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
