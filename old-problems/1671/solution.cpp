#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimumMountainRemovals(std::vector<int>& nums) {
    std::vector<int> ans(nums.size() - 2);

    std::vector<int> stack{};
    stack.reserve(nums.size());
    stack.push_back(nums.front());

    for (std::size_t i{0}; i < ans.size(); ++i) {
      if (stack.back() < nums[i + 1]) {
        stack.push_back(nums[i + 1]);
        ans[i] = stack.size();
      } else {
        auto it = std::lower_bound(stack.begin(), stack.end(), nums[i + 1]);
        *it = nums[i + 1];
        ans[i] = std::distance(stack.begin(), it + 1);
      }
    }

    stack.clear();
    stack.push_back(nums.back());

    for (std::size_t i{ans.size()}; i > 0; --i) {
      if (stack.back() < nums[i]) {
        stack.push_back(nums[i]);
        if (ans[i - 1] > 1) ans[i - 1] += stack.size();
      } else {
        auto it = std::lower_bound(stack.begin(), stack.end(), nums[i]);
        *it = nums[i];
        if (ans[i - 1] > 1) {
          const auto size = std::distance(stack.begin(), it + 1);
          if (size == 1) {
            ans[i - 1] = 1;
          } else {
            ans[i - 1] += size;
          }
        }
      }
    }

    return nums.size() + 1 - *std::max_element(ans.begin(), ans.end());
  }
};
