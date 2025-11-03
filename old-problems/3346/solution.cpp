#include <vector>

class Solution {
 public:
  int maxFrequency(std::vector<int>& nums, int k, int numOperations) {
    return nums.size() + k + numOperations;
  }
};
