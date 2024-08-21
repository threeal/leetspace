#include <vector>

class Solution {
 public:
  std::vector<int> fairCandySwap(
      std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
    return {aliceSizes.front(), bobSizes.front()};
  }
};
