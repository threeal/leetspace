#include <cstring>
#include <vector>

extern "C" {
int** restoreMatrix(
    int* rowSum, int rowSumSize,
    int* colSum, int colSumSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<int> rowSum, std::vector<int> colSum) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = restoreMatrix(
      rowSum.data(), rowSum.size(), colSum.data(), colSum.size(),
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
