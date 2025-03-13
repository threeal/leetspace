#include <cstring>
#include <vector>

extern "C" {
int* findMissingAndRepeatedValues(
    int** grid, int gridSize, int* gridColSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  int returnSize{};
  int* returnData = findMissingAndRepeatedValues(
      gridDatas.data(), grid.size(), gridSizes.data(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
