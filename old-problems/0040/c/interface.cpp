#include <cstring>
#include <vector>

extern "C" {
int** combinationSum2(
    int* candidates, int candidatesSize, int target,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<int> candidate, int target) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = combinationSum2(
      candidate.data(), candidate.size(), target,
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
  }

  return output;
}
