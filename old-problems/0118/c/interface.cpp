#include <cstring>
#include <vector>

extern "C" {
int** generate(int numRows, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(int numRows) {
  int returnSize{};
  int* returnColumnSizes{};
  auto returnData = generate(numRows, &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i{0}; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
