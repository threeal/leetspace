#include <cstring>
#include <vector>

extern "C" {
int** reconstructMatrix(
    int upper, int lower, int* colsum, int colsumSize,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    int upper, int lower, std::vector<int> colsum) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = reconstructMatrix(
      upper, lower, colsum.data(), colsum.size(),
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
