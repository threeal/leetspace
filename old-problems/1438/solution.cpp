#include <deque>
#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums, int limit) {
    int longest{0};

    std::deque<int> increasing{};
    std::deque<int> decreasing{};
    for (int left = nums.size() - 1, right = left; left >= 0; --left) {
      while (!increasing.empty() && increasing.back() > nums[left]) {
        increasing.pop_back();
      }
      increasing.push_back(nums[left]);

      while (!decreasing.empty() && decreasing.back() < nums[left]) {
        decreasing.pop_back();
      }
      decreasing.push_back(nums[left]);

      while (decreasing.front() - increasing.front() > limit) {
        if (nums[right] == increasing.front()) increasing.pop_front();
        if (nums[right] == decreasing.front()) decreasing.pop_front();
        --right;
      }

      if (right - left + 1 > longest) longest = right - left + 1;
    }

    return longest;
  }
};
