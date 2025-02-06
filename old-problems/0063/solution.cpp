#include <vector>

class Solution {
 public:
  int uniquePathsWithObstacles(
      std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] != 0) return 0;
    obstacleGrid[0][0] = 1;

    for (std::size_t j{1}; j < obstacleGrid[0].size(); ++j) {
      if (obstacleGrid[0][j] == 0) {
        obstacleGrid[0][j] = obstacleGrid[0][j - 1];
      } else {
        obstacleGrid[0][j] = 0;
      }
    }

    for (std::size_t i{1}; i < obstacleGrid.size(); ++i) {
      if (obstacleGrid[i][0] == 0) {
        obstacleGrid[i][0] = obstacleGrid[i - 1][0];
      } else {
        obstacleGrid[i][0] = 0;
      }

      for (std::size_t j{1}; j < obstacleGrid[i].size(); ++j) {
        if (obstacleGrid[i][j] == 0) {
          obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        } else {
          obstacleGrid[i][j] = 0;
        }
      }
    }

    return obstacleGrid.back().back();
  }
};
