#include <cstring>
#include <vector>

extern "C" {
int** combinationSum(
    int* candidates, int candidatesSize, int target,
    int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(
    std::vector<int> candidates, int target) {
  int returnSize{};
  int* returnColumnSizes{};
  const auto returnData = combinationSum(
      candidates.data(), candidates.size(), target,
      &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i].resize(returnColumnSizes[0]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[0] * sizeof(int));
  }

  return output;
}
