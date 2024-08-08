#include <vector>

class Solution {
 public:
  int minSwaps(std::vector<int>& nums) {
    int ones{0};
    for (const auto num : nums) {
      if (num == 1) ++ones;
    }
    if (ones == 0) return 0;

    int zeros{0};
    for (std::size_t i{nums.size() - ones + 1}; i < nums.size(); ++i) {
      if (nums[i] == 0) ++zeros;
    }

    int minZeros{ones};
    int left = nums.size() - ones;
    int right = nums.size() - 1;
    while (left >= 0) {
      if (nums[left] == 0) ++zeros;
      if (zeros < minZeros) minZeros = zeros;
      if (nums[right] == 0) --zeros;
      --left;
      --right;
    }

    left += nums.size();
    while (right >= 0) {
      if (nums[left] == 0) ++zeros;
      if (zeros < minZeros) minZeros = zeros;
      if (nums[right] == 0) --zeros;
      --left;
      --right;
    }

    return minZeros;
  }
};
