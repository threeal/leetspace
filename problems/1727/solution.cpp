// We will do a brute force search here to find the maximum area of the submatrix.
// But before that, we need to adjust each element of the matrix so it contains
// 1 + the number of the above elements whose value is 1.
//
// Given the example input:
//
//   [ 0 0 1 ]
//   [ 1 1 1 ]
//   [ 1 0 1 ]
//
// We will adjust it to be:
//
//   [ 0 0 1 ]
//   [ 1 1 2 ]
//   [ 2 0 3 ]
//
// And then we can just iterate each row to find the maximum area.
// To calculate each row, we can sort the row first from highest to lowest
// and then calculate the area by multiplying the element value with the element index + 1.
//
// Given the second row of the adjusted example matrix:
//
//   [ 1 2 2 ]
//
// We can sort it to be:
//
//   [ 2 2 1 ]
//
// And we can just choose the largest area as follows:
//
//   2 * 1 = 2
//   2 * 2 = 4 (largest)
//   1 * 3 = 3

#include <algorithm>
#include <vector>

class Solution {
 public:
  int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
    // Adjust each element of the matrix so it contains
    // 1 + the number of the above elements whose value is 1.
    for (std::size_t y = 1; y < matrix.size(); ++y) {
      for (std::size_t x = 0; x < matrix[y].size(); ++x) {
        if (matrix[y][x] == 0) continue;
        matrix[y][x] = matrix[y - 1][x] + 1;
      }
    }

    // Do brute force search here to calculate the maximum area.
    int maxArea = 0;
    for (auto& rows : matrix) {
      // Sort values in the row from highest to lowest.
      sort(rows.begin(), rows.end(), std::greater<int>());

      // Find the largest area from values in the row.
      for (std::size_t i = 0; i < rows.size(); ++i) {
        if (rows[i] == 0) break;
        maxArea = std::max<int>(maxArea, (i + 1) * rows[i]);
      }
    }

    return maxArea;
  }
};
