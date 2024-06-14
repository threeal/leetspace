#include <algorithm>
#include <limits>
#include <stack>
#include <tuple>
#include <vector>

class Solution {
 public:
  int minIncrementForUnique(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::stack<std::tuple<int, int>> availables{};
    availables.push({nums.back() + 1, std::numeric_limits<int>::max()});

    int moves{0};
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] == nums[i + 1]) {
        auto& [min, max] = availables.top();
        moves += min - nums[i];
        if (++min > max) availables.pop();
      } else if (nums[i] + 1 < nums[i + 1]) {
        availables.push({nums[i] + 1, nums[i + 1] - 1});
      }
    }

    return moves;
  }
};
