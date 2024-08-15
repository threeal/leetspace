#include <cstring>
#include <vector>

extern "C" {
int** spiralMatrixIII(
    int rows, int cols, int rStart, int cStart,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    int rows, int cols, int rStart, int cStart) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = spiralMatrixIII(
      rows, cols, rStart, cStart, &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
