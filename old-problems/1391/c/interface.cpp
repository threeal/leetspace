#include <vector>

extern "C" {
bool hasValidPath(int** grid, int gridSize, int* gridColSize);
}

bool solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  return hasValidPath(gridDatas.data(), grid.size(), gridSizes.data());
}
