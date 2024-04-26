#include <algorithm>
#include <deque>
#include <vector>

class Solution {
 public:
  int constrainedSubsetSum(std::vector<int>& nums, int k) {
    std::deque<int> dq;

    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (!dq.empty()) nums[i] += nums[dq.front()];

      while (!dq.empty() && (i - dq.front() >= k || nums[i] >= nums[dq.back()])) {
        if (nums[i] >= nums[dq.back()])
          dq.pop_back();
        else
          dq.pop_front();
      }

      if (nums[i] > 0) dq.push_back(i);
    }

    return *max_element(nums.begin(), nums.end());
  }
};
