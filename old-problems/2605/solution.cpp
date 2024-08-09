#include <bit>
#include <vector>

class Solution {
 public:
  int minNumber(std::vector<int>& nums1, std::vector<int>& nums2) {
    unsigned int first{0}, second{0};
    for (const auto num : nums1) first |= 1 << num;
    for (const auto num : nums2) second |= 1 << num;
    if ((first & second) > 0) return std::countr_zero(first & second);
    first = std::countr_zero(first);
    second = std::countr_zero(second);
    return first < second ? first * 10 + second : second * 10 + first;
  }
};
