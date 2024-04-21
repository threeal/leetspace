#include <vector>

extern "C" {
int numIslands(char** grid, int gridSize, int* gridColSize);
}

int solution_c(std::vector<std::vector<char>> grid) {
  std::vector<char*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  return numIslands(gridDatas.data(), gridDatas.size(), gridSizes.data());
}
