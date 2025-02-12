#include <vector>

extern "C" {
int uniquePathsWithObstacles(
    int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);
}

int solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> obstacleGridDatas(grid.size());
  std::vector<int> obstacleGridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    obstacleGridDatas[i] = grid[i].data();
    obstacleGridSizes[i] = grid[i].size();
  }

  return uniquePathsWithObstacles(
      obstacleGridDatas.data(), obstacleGridDatas.size(),
      obstacleGridSizes.data());
}
