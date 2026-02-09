#include <queue>
#include <vector>

class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int> negLargest{};
    for (int i{0}; i < k; ++i) {
      negLargest.push(-nums[i]);
    }

    const int n = nums.size();
    for (int i{k}; i < n; ++i) {
      if (nums[i] > -negLargest.top()) {
        negLargest.pop();
        negLargest.push(-nums[i]);
      }
    }

    return -negLargest.top();
  }
};
