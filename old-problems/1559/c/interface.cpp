#include <vector>

extern "C" {
bool containsCycle(char** grid, int gridSize, int* gridColSize);
}

bool solution_c(std::vector<std::vector<char>> grid) {
  std::vector<char*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }
  return containsCycle(gridDatas.data(), grid.size(), gridSizes.data());
}
