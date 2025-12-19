#include <vector>

class Solution {
 public:
  int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings) {
    std::vector<int> xMins(n + 1, std::numeric_limits<int>::max());
    std::vector<int> xMaxs(n + 1, std::numeric_limits<int>::min());
    std::vector<int> yMins(n + 1, std::numeric_limits<int>::max());
    std::vector<int> yMaxs(n + 1, std::numeric_limits<int>::min());

    for (const auto& b : buildings) {
      if (b[0] < yMins[b[1]]) yMins[b[1]] = b[0];
      if (b[0] > yMaxs[b[1]]) yMaxs[b[1]] = b[0];
      if (b[1] < xMins[b[0]]) xMins[b[0]] = b[1];
      if (b[1] > xMaxs[b[0]]) xMaxs[b[0]] = b[1];
    }

    int count{0};
    for (const auto& b : buildings) {
      if (b[0] > yMins[b[1]] && b[0] < yMaxs[b[1]] &&
          b[1] > xMins[b[0]] && b[1] < xMaxs[b[0]]) ++count;
    }

    return count;
  }
};
