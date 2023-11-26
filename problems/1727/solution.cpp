#include <algorithm>
#include <vector>

class Solution {
 public:
  int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
    for (size_t y = 1; y < matrix.size(); ++y) {
      for (size_t x = 0; x < matrix[y].size(); ++x) {
        if (matrix[y][x] == 0) continue;
        matrix[y][x] = matrix[y - 1][x] + 1;
      }
    }

    int maxArea = 0;
    for (auto& rows : matrix) {
      sort(rows.begin(), rows.end(), std::greater<int>());

      for (size_t i = 0; i < rows.size(); ++i) {
        maxArea = std::max<int>(maxArea, (i + 1) * rows[i]);
      }
    }

    return maxArea;
  }
};
