#include <cstring>
#include <vector>

extern "C" {
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (int i = grid.size() - 1; i >= 0; --i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData{largestLocal(gridDatas.data(), gridDatas.size(), gridSizes.data(), &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (int i{returnSize - 1}; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
