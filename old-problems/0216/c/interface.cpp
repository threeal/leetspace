#include <cstring>
#include <vector>

extern "C" {
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(int k, int n) {
  int returnSize{};
  int* returnColumnSizes{};
  int** returnData{combinationSum3(k, n, &returnSize, &returnColumnSizes)};

  std::vector<std::vector<int>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], output[i].size() * sizeof(int));
  }

  return output;
}
