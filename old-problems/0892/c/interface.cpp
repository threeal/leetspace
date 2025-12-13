#include <vector>

extern "C" {
int surfaceArea(int** grid, int gridSize, int* gridColSize);
}

int solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  return surfaceArea(gridDatas.data(), grid.size(), gridSizes.data());
}
