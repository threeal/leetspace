#include <cstring>
#include <vector>

extern "C" {
int** constructProductMatrix(
    int** grid, int gridSize, int* gridColSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<std::vector<int>> grid) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      constructProductMatrix(
          gridDatas.data(), grid.size(), gridSizes.data(),
          &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> out(returnSize);
  for (std::size_t i{0}; i < out.size(); ++i) {
    out[i].resize(returnColumnSizes[i]);
    std::memcpy(out[i].data(), returnData[i], out[i].size() * sizeof(int));
  }

  return out;
}
