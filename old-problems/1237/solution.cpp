#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findSolution(
      CustomFunction& customfunction, int z) {
    std::vector<std::vector<int>> output{};

    int x{1};
    while (customfunction.f(x, 1) <= z) {
      int ly{1}, ry{1000};
      while (ly < ry) {
        const int y{ly + (ry - ly) / 2};
        if (customfunction.f(x, y) < z) {
          ly = y + 1;
        } else {
          ry = y;
        }
      }

      if (customfunction.f(x, ly) == z) {
        output.push_back({x, ly});
      }

      ++x;
    }

    return output;
  }
};
