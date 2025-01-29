#include <vector>

class Solution {
 public:
  bool search(std::vector<int>& nums, int target) {
    return nums.front() == target;
  }
};
