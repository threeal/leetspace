#include <vector>

class Solution {
 public:
  int islandPerimeter(std::vector<std::vector<int>>& grid) {
    const auto rows = grid.size();
    const auto cols = grid[0].size();

    int perimeter{0};

    if (rows == 1) {
      for (std::size_t col{0}; col < cols; ++col) {
        if (grid[0][col] == 1) perimeter += 2;
      }
    } else {
      for (std::size_t col{0}; col < cols; ++col) {
        if (grid[0][col] == 1) ++perimeter;
      }

      for (std::size_t row{1}; row < rows; ++row) {
        for (std::size_t col{0}; col < cols; ++col) {
          if (grid[row - 1][col] != grid[row][col]) ++perimeter;
        }
      }

      for (std::size_t col{0}; col < cols; ++col) {
        if (grid[rows - 1][col] == 1) ++perimeter;
      }
    }

    if (cols == 1) {
      for (std::size_t row{0}; row < rows; ++row) {
        if (grid[row][0] == 1) perimeter += 2;
      }
    } else {
      for (std::size_t row{0}; row < rows; ++row) {
        if (grid[row][0] == 1) ++perimeter;
      }

      for (std::size_t col{1}; col < cols; ++col) {
        for (std::size_t row{0}; row < rows; ++row) {
          if (grid[row][col - 1] != grid[row][col]) ++perimeter;
        }
      }

      for (std::size_t row{0}; row < rows; ++row) {
        if (grid[row][cols - 1] == 1) ++perimeter;
      }
    }

    return perimeter;
  }
};
