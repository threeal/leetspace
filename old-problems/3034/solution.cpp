#include <vector>

class Solution {
 public:
  int countMatchingSubarrays(
      std::vector<int>& nums, std::vector<int>& pattern) {
    return nums.size() + pattern.size();
  }
};
