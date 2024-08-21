#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> fairCandySwap(
      std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
    std::sort(aliceSizes.begin(), aliceSizes.end());
    std::sort(bobSizes.begin(), bobSizes.end());

    const auto aliceSum = std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    const auto bobSum = std::accumulate(bobSizes.begin(), bobSizes.end(), 0);

    if (aliceSum <= bobSum) {
      const auto diff = (bobSum - aliceSum) / 2;
      auto bobIt = bobSizes.begin();
      for (const auto alice : aliceSizes) {
        bobIt = std::lower_bound(bobIt, bobSizes.end(), alice + diff);
        if (alice + diff == *bobIt) return {alice, *bobIt};
      }
    } else {
      const auto diff = (aliceSum - bobSum) / 2;
      auto aliceIt = aliceSizes.begin();
      for (const auto bob : bobSizes) {
        aliceIt = std::lower_bound(aliceIt, aliceSizes.end(), bob + diff);
        if (bob + diff == *aliceIt) return {*aliceIt, bob};
      }
    }

    return {};
  }
};
