#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> findBall(std::vector<std::vector<int>>& grid) {
    const int n = grid[0].size();

    std::vector<int> balls(n);
    std::iota(balls.begin(), balls.end(), 0);

    for (const std::vector<int>& level : grid) {
      for (int& ball : balls) {
        if (ball >= 0) {
          if (level[ball] == 1) {
            if (ball + 1 < n && level[ball + 1] == 1) {
              ++ball;
            } else {
              ball = -1;
            }
          } else {
            if (ball > 0 && level[ball - 1] != 1) {
              --ball;
            } else {
              ball = -1;
            }
          }
        }
      }
    }

    return balls;
  }
};
