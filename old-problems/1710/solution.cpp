#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    std::sort(
        boxTypes.begin(), boxTypes.end(),
        [](const auto& a, const auto& b) {
          return a[1] > b[1];
        });

    int units{0};
    for (const auto& boxTypes : boxTypes) {
      const int boxes{std::min(boxTypes[0], truckSize)};
      units += boxes * boxTypes[1];
      truckSize -= boxes;
      if (truckSize == 0) break;
    }

    return units;
  }
};
