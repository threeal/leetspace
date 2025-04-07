#include <cstring>
#include <vector>

extern "C" {
int* maxPoints(
    int** grid, int gridSize, int* gridColSize,
    int* queries, int queriesSize, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<std::vector<int>> grid, std::vector<int> queries) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  int returnSize{};
  const auto returnData = maxPoints(
      gridDatas.data(), grid.size(), gridSizes.data(),
      queries.data(), queries.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
