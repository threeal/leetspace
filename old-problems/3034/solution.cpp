#include <vector>

class Solution {
 public:
  int countMatchingSubarrays(
      std::vector<int>& nums, std::vector<int>& pattern) {
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        nums[i - 1] = 0;
      } else if (nums[i] > nums[i - 1]) {
        nums[i - 1] = 1;
      } else {
        nums[i - 1] = -1;
      }
    }

    int count{0};
    for (std::size_t i{0}; i + pattern.size() < nums.size(); ++i) {
      std::size_t j{0};
      while (j < pattern.size() && nums[i + j] == pattern[j]) ++j;
      if (j == pattern.size()) ++count;
    }

    return count;
  }
};
