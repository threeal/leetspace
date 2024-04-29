#include <vector>

extern "C" {
int minFallingPathSum(int** grid, int gridSize, int* gridColSize);
}

int solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  return minFallingPathSum(gridDatas.data(), gridDatas.size(), gridSizes.data());
}
