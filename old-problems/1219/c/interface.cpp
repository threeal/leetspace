#include <vector>

extern "C" {
int getMaximumGold(int** grid, int gridSize, int* gridColSize);
}

int solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (int i = grid.size() - 1; i >= 0; --i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  return getMaximumGold(gridDatas.data(), gridDatas.size(), gridSizes.data());
}
