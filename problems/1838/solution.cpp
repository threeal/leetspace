// TLDR: I don't know how they derived this solution, I just found it in the editorial:
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/editorial/

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxFrequency(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());

    size_t left = 0;
    long curr = 0;
    for (size_t right = 0; right < nums.size(); ++right) {
      curr += nums[right];
      if (long(right - left + 1) * nums[right] - curr > k) {
        curr -= nums[left];
        ++left;
      }
    }

    return nums.size() - left;
  }
};
