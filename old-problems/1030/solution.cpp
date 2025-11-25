#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> allCellsDistOrder(
      int rows, int cols, int rCenter, int cCenter) {
    return {{rows, cols, rCenter, cCenter}};
  }
};
