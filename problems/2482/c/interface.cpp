#include <cstring>
#include <vector>

extern "C" {
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i = 0; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  int returnSize;
  int* returnColumnSizes;
  onesMinusZeros(gridDatas.data(), gridDatas.size(), gridSizes.data(), &returnSize, &returnColumnSizes);
  return grid;
}
