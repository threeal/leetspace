#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int maxRemoval(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    std::sort(queries.begin(), queries.end());

    for (std::size_t i{nums.size() - 1}; i > 0; --i) {
      nums[i] -= nums[i - 1];
    }

    int num{0};
    std::priority_queue<int> ends{};
    for (std::size_t i{0}, j{0}; i < nums.size(); ++i) {
      num += nums[i];
      while (
          j < queries.size() &&
          static_cast<std::size_t>(queries[j][0]) == i) {
        ends.push(queries[j][1]);
        ++j;
      }

      while (
          num > 0 &&
          !ends.empty() &&
          i <= static_cast<std::size_t>(ends.top())) {
        --num;
        if (static_cast<std::size_t>(ends.top()) + 1 < nums.size()) {
          ++nums[ends.top() + 1];
        }
        ends.pop();
      }

      if (num > 0) return -1;
    }

    return ends.size();
  }
};
