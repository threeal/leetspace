#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

class Solution {
 private:
  using Move = std::tuple<int, std::size_t, std::size_t>;

 public:
  int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
    const std::size_t ty{moveTime.size() - 1};
    const std::size_t tx{moveTime[ty].size() - 1};

    std::priority_queue<Move, std::vector<Move>, std::greater<Move>> moves{};

    moves.push({0, 0, 0});
    moveTime[0][0] = -1;

    while (!moves.empty()) {
      const auto [time, y, x] = moves.top();
      moves.pop();

      if (y > 0 && moveTime[y - 1][x] >= 0) {
        const int nextTime{std::max(time, moveTime[y - 1][x]) + 1};
        if (y - 1 == ty && x == tx) return nextTime;
        moves.push({nextTime, y - 1, x});
        moveTime[y - 1][x] = -1;
      }

      if (y < ty && moveTime[y + 1][x] >= 0) {
        const int nextTime{std::max(time, moveTime[y + 1][x]) + 1};
        if (y + 1 == ty && x == tx) return nextTime;
        moves.push({nextTime, y + 1, x});
        moveTime[y + 1][x] = -1;
      }

      if (x > 0 && moveTime[y][x - 1] >= 0) {
        const int nextTime{std::max(time, moveTime[y][x - 1]) + 1};
        if (y == ty && x - 1 == tx) return nextTime;
        moves.push({nextTime, y, x - 1});
        moveTime[y][x - 1] = -1;
      }

      if (x < tx && moveTime[y][x + 1] >= 0) {
        const int nextTime{std::max(time, moveTime[y][x + 1]) + 1};
        if (y == ty && x + 1 == tx) return nextTime;
        moves.push({nextTime, y, x + 1});
        moveTime[y][x + 1] = -1;
      }
    }

    return -1;
  }
};
