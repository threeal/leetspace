#include <vector>

class Solution {
 public:
  int latestDayToCross(int row, int col, std::vector<std::vector<int>>& cells) {
    return row + col + cells.size();
  }
};
