#include <vector>

extern "C" {
int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k);
}

int solution_c(std::vector<std::vector<int>> grid, int k) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  return numberOfPaths(gridDatas.data(), grid.size(), gridSizes.data(), k);
}
