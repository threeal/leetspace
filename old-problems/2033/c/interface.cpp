#include <vector>

extern "C" {
int minOperations(int** grid, int gridSize, int* gridColSize, int x);
}

int solution_c(std::vector<std::vector<int>> grid, int x) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  return minOperations(gridDatas.data(), grid.size(), gridSizes.data(), x);
}
