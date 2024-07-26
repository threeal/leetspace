#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> output{};

    int d = nums.size() - 1;
    while (d >= 3) {
      int c{d - 1};
      while (c >= 2) {
        int b{c - 1};
        while (b >= 1) {
          const long long num =
              static_cast<long long>(target) - nums[b] - nums[c] - nums[d];
          const auto it = std::lower_bound(
              nums.begin(), nums.begin() + b - 1, num);
          if (*it == num) {
            output.push_back({*it, nums[b], nums[c], nums[d]});
          }
          --b;
          while (b >= 1 && nums[b] == nums[b + 1]) --b;
        }
        --c;
        while (c >= 2 && nums[c] == nums[c + 1]) --c;
      }
      --d;
      while (d >= 3 && nums[d] == nums[d + 1]) --d;
    }

    return output;
  }
};
