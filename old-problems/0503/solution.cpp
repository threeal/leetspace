#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> nextGreaterElements(std::vector<int>& nums) {
    std::size_t greatestI{0};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] > nums[greatestI]) greatestI = i;
    }

    std::stack<int> greaters{};
    greaters.push(nums[greatestI]);

    nums[greatestI] = -1;

    std::size_t i{greatestI == 0 ? nums.size() - 1 : greatestI - 1};
    while (i != greatestI) {
      while (!greaters.empty() && greaters.top() <= nums[i]) {
        greaters.pop();
      }

      const int prev{nums[i]};
      nums[i] = greaters.empty() ? -1 : greaters.top();
      greaters.push(prev);

      if (i == 0) {
        i = nums.size() - 1;
      } else {
        --i;
      }
    }

    return nums;
  }
};
