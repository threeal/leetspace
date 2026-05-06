#include <cstring>
#include <vector>

extern "C" {
int** shiftGrid(
    int** grid, int gridSize, int* gridColSize, int k,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<std::vector<int>> grid, int k) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      shiftGrid(
          gridDatas.data(), grid.size(), gridSizes.data(), k,
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
