#include <limits>
#include <stack>
#include <vector>

class Solution {
 public:
  bool find132pattern(std::vector<int>& nums) {
    std::stack<int> js;
    js.push(std::numeric_limits<int>::max());
    int k = std::numeric_limits<int>::min();
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < k) return true;
      while (nums[i] > js.top()) {
        k = js.top();
        js.pop();
      }
      js.push(nums[i]);
    }

    return false;
  }
};
