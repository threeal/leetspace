#include <vector>

class Solution {
 public:
  int countUnguarded(
      int m, int n, std::vector<std::vector<int>>& guards,
      std::vector<std::vector<int>>& walls) {
    std::vector<std::vector<char>> cells(m, std::vector<char>(n, 0));

    for (const auto& guard : guards) cells[guard[0]][guard[1]] = 1;
    for (const auto& wall : walls) cells[wall[0]][wall[1]] = 2;

    for (const auto& guard : guards) {
      for (int i{guard[0] + 1}; i < m && cells[i][guard[1]] <= 0; ++i) {
        cells[i][guard[1]] = -1;
      }

      for (int i{guard[0] - 1}; i >= 0 && cells[i][guard[1]] <= 0; --i) {
        cells[i][guard[1]] = -1;
      }

      for (int i{guard[1] + 1}; i < n && cells[guard[0]][i] <= 0; ++i) {
        cells[guard[0]][i] = -1;
      }

      for (int i{guard[1] - 1}; i >= 0 && cells[guard[0]][i] <= 0; --i) {
        cells[guard[0]][i] = -1;
      }
    }

    int unguarded{0};
    for (const auto& row : cells) {
      for (const auto cell : row) {
        if (cell == 0) ++unguarded;
      }
    }

    return unguarded;
  }
};
