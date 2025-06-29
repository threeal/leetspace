#include <vector>

class Solution {
 public:
  int numSubseq(std::vector<int>& nums, int target) {
    return nums.size() + target;
  }
};
