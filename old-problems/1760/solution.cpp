#include <vector>

class Solution {
 public:
  int minimumSize(std::vector<int>& nums, int maxOperations) {
    return nums.front() / maxOperations;
  }
};
