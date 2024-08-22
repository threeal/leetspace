#include <cstring>
#include <vector>

extern "C" {
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(int n) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = generateMatrix(n, &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
