#include <cstring>
#include <vector>

extern "C" {
int** construct2DArray(
    int* original, int originalSize, int m, int n,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<int> original, int m, int n) {
  int returnSize;
  int* returnColumnSizes;
  const auto returnData = construct2DArray(
      original.data(), original.size(), m, n, &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{returnSize - 1}; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
