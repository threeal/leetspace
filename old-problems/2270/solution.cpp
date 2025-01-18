#include <numeric>
#include <vector>

class Solution {
 public:
  int waysToSplitArray(std::vector<int>& nums) {
    long long right{std::accumulate(nums.begin(), nums.end(), 0ll)};
    nums.pop_back();

    long long left{0};
    int count{0};
    for (const auto num : nums) {
      left += num;
      right -= num;
      if (left >= right) ++count;
    }

    return count;
  }
};
