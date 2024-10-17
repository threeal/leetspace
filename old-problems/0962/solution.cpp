#include <stack>
#include <vector>

class Solution {
 public:
  int maxWidthRamp(std::vector<int>& nums) {
    std::stack<int> decreasing{};
    decreasing.push(0);

    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] < nums[decreasing.top()]) {
        decreasing.push(i);
        if (nums[i] == 0) break;
      }
    }

    int ramp{0};
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (nums[decreasing.top()] <= nums[i]) {
        if (i - decreasing.top() > ramp) ramp = i - decreasing.top();
        decreasing.pop();
        if (decreasing.empty()) return ramp;
      }
    }

    return ramp;
  }
};
