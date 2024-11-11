#include <bit>
#include <vector>

class Solution {
 public:
  bool canSortArray(std::vector<int>& nums) {
    int prevMax{0}, max{0}, bitCount{-1};
    for (const auto num : nums) {
      const auto count = std::popcount(static_cast<unsigned int>(num));
      if (count == bitCount) {
        if (num < prevMax) return false;
        if (num > max) max = num;
      } else {
        if (num < max) return false;
        bitCount = count;
        prevMax = max;
        max = num;
      }
    }

    return true;
  }
};
