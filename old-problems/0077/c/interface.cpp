#include <cstring>
#include <vector>

extern "C" {
int** combine(int n, int k, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(int n, int k) {
  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{
      combine(n, k, &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
