#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
    const int n = matrix.size();

    // Skip if matrix size is 1.
    if (n == 1) return matrix[0][0];

    // Iterating from the bottom row to recursively calculate the minimum distance from the below row.
    for (int y = n - 2; y >= 0; --y) {
      // Leftmost column.
      matrix[y][0] += std::min(matrix[y + 1][0], matrix[y + 1][1]);

      for (int x = 1; x < n - 1; ++x) {
        matrix[y][x] += std::min(
            std::min(matrix[y + 1][x - 1], matrix[y + 1][x]),
            matrix[y + 1][x + 1]);
      }

      // Rightmost column.
      matrix[y][n - 1] += std::min(matrix[y + 1][n - 2], matrix[y + 1][n - 1]);
    }

    // The minimum distance can be found in the topmost row.
    int minVal = std::numeric_limits<int>::max();
    for (const auto val : matrix[0]) {
      if (val < minVal) minVal = val;
    }

    return minVal;
  }
};
