#include <vector>

class Solution {
 public:
  std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid) {
    std::vector<int> maxWidths(grid[0].size(), 1);
    for (const auto& row : grid) {
      for (std::size_t i{0}; i < row.size(); ++i) {
        int num{row[i] / 10}, width{1};
        if (row[i] < 0) {
          num = -num;
          ++width;
        }

        while (num > 0) {
          num /= 10;
          ++width;
        }

        if (width > maxWidths[i]) maxWidths[i] = width;
      }
    }
    return maxWidths;
  }
};
