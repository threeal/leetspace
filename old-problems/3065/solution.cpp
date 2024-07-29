#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int k) {
    int count{0};
    for (const auto num : nums) {
      if (num < k) ++count;
    }
    return count;
  }
};
