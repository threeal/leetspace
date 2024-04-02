#include <cstring>
#include <vector>

extern "C" {
int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<int> nums, int k) {
  int returnSize;
  int* returnColumnSizes = NULL;
  const auto returnData = divideArray(nums.data(), nums.size(), k, &returnSize, &returnColumnSizes);

  std::vector<std::vector<int>> output(returnSize);
  for (int i = 0; i < returnSize; ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(int));
    free(returnData[i]);
  }

  if (returnData != NULL) free(returnData);
  if (returnColumnSizes != NULL) free(returnColumnSizes);

  return output;
}
