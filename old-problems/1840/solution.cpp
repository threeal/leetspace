#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxBuilding(
      int n, std::vector<std::vector<int>>& restrictions) {
    if (restrictions.empty()) return n - 1;

    std::sort(
        restrictions.begin(), restrictions.end(),
        [](const auto& a, const auto& b) {
          return a[0] < b[0];
        });

    return restrictions[0][0];
  }
};
