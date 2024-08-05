#include <queue>
#include <vector>

class Solution {
 public:
  int snakesAndLadders(std::vector<std::vector<int>>& board) {
    const int n = board.size();
    const int end{n * n - 1};

    std::queue<int> positions{};
    positions.push(0);

    for (int moves{1}; !positions.empty(); ++moves) {
      for (std::size_t i{positions.size()}; i > 0; --i) {
        const int pos{positions.front()};
        positions.pop();

        if (pos + 6 >= end) return moves;
        for (int next{pos + 6}; next > pos; --next) {
          const int y{n - 1 - next / n};
          const int x{(next / n) % 2 == 0 ? next % n : n - 1 - next % n};
          if (board[y][x] > 0) {
            const int next{board[y][x] - 1};
            board[y][x] = 0;
            if (next == end) return moves;
            positions.push(next);
          } else if (board[y][x] < 0) {
            board[y][x] = 0;
            positions.push(next);
          }
        }
      }
    }

    return -1;
  }
};
