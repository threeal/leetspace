#include <queue>
#include <vector>

class Solution {
 public:
  int snakesAndLadders(std::vector<std::vector<int>>& board) {
    const int n = board.size();
    const int end = n * n - 1;

    std::vector<int> line{};
    line.reserve(n * n);
    bool right{true};
    for (int i{n - 1}; i >= 0; --i) {
      if (right) {
        for (int j{0}; j < n; ++j) line.push_back(board[i][j]);
        right = false;
      } else {
        for (int j{n - 1}; j >= 0; --j) line.push_back(board[i][j]);
        right = true;
      }
    }

    std::queue<int> positions{};
    positions.push(0);

    for (int moves{1}; !positions.empty(); ++moves) {
      for (std::size_t i{positions.size()}; i > 0; --i) {
        const int pos{positions.front()};
        positions.pop();

        if (pos + 6 >= end) return moves;
        for (int j{1}; j <= 6; ++j) {
          int next = pos + j;
          if (line[next] > 0) {
            const auto temp = line[next];
            line[next] = 0;
            next = temp - 1;
            if (next == end) return moves;
            positions.push(next);
          } else if (line[next] < 0) {
            line[next] = 0;
            positions.push(next);
          }
        }
      }
    }

    return -1;
  }
};
