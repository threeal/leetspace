#include <cstdint>
#include <vector>

class Solution {
 public:
  bool isCovered(std::vector<std::vector<int>>& ranges, int left, int right) {
    std::uint64_t actual{0};
    for (const auto& range : ranges) {
      actual |= ((1ul << (range[1] + 1)) - 1) & ~((1ul << range[0]) - 1);
    }
    std::uint64_t expected = ((1ul << (right + 1)) - 1) & ~((1ul << left) - 1);
    return (actual & expected) == expected;
  }
};
