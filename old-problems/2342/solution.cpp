#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumSum(std::vector<int>& nums) {
    std::vector<int> sums(nums.size());
    std::vector<std::size_t> indexes(nums.size());
    for (std::size_t i{0}; i < nums.size(); ++i) {
      int sum{0}, num{nums[i]};
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      sums[i] = sum;
      indexes[i] = i;
    }

    std::sort(
      indexes.begin(), indexes.end(),
      [&sums, &nums](std::size_t a, std::size_t b) {
        return sums[a] == sums[b] ? nums[a] < nums[b] : sums[a] < sums[b];
      });

    int max{-1};
    for (std::size_t i{1}; i < indexes.size(); ++i) {
      if (sums[indexes[i]] == sums[indexes[i - 1]]) {
        if (nums[indexes[i]] + nums[indexes[i - 1]] > max) {
          max = nums[indexes[i]] + nums[indexes[i - 1]];
        }
      }
    }

    return max;
  }
};
