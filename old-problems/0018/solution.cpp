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
        const auto targetSum =
            static_cast<long long>(target) - nums[c] - nums[d];

        int a{0};
        int b{c - 1};
        while (a < b) {
          const auto sum = static_cast<long long>(nums[a]) + nums[b];
          if (sum == targetSum) {
            output.push_back({nums[a], nums[b], nums[c], nums[d]});
          }

          if (sum < targetSum) {
            ++a;
            while (a < b && nums[a] == nums[a - 1]) ++a;
          } else {
            --b;
            while (a < b && nums[b] == nums[b + 1]) --b;
          }
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
