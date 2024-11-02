#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  int maxMoves(std::vector<std::vector<int>>& grid) {
    std::vector<int> moves(grid.size(), 0);
    std::vector<int> nextMoves(grid.size());

    for (int i = grid.back().size() - 2; i >= 0; --i) {
      std::swap(moves, nextMoves);

      int j = moves.size() - 1;
      moves[j] = 0;
      if (grid[j][i] < grid[j - 1][i + 1] && moves[j] < 1 + nextMoves[j - 1]) {
        moves[j] = 1 + nextMoves[j - 1];
      }
      if (grid[j][i] < grid[j][i + 1] && moves[j] < 1 + nextMoves[j]) {
        moves[j] = 1 + nextMoves[j];
      }

      for (--j; j > 0; --j) {
        moves[j] = 0;
        if (grid[j][i] < grid[j - 1][i + 1] && moves[j] < 1 + nextMoves[j - 1]) {
          moves[j] = 1 + nextMoves[j - 1];
        }
        if (grid[j][i] < grid[j][i + 1] && moves[j] < 1 + nextMoves[j]) {
          moves[j] = 1 + nextMoves[j];
        }
        if (grid[j][i] < grid[j + 1][i + 1] && moves[j] < 1 + nextMoves[j + 1]) {
          moves[j] = 1 + nextMoves[j + 1];
        }
      }

      moves[0] = 0;
      if (grid[0][i] < grid[0][i + 1] && moves[0] < 1 + nextMoves[0]) {
        moves[0] = 1 + nextMoves[0];
      }
      if (grid[0][i] < grid[1][i + 1] && moves[0] < 1 + nextMoves[1]) {
        moves[0] = 1 + nextMoves[1];
      }
    }

    return *std::max_element(moves.begin(), moves.end());
  }
};
