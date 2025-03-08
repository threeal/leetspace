#include <cstring>
#include <vector>

extern "C" {
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int pivot) {
  int returnSize;
  const auto returnData = pivotArray(
      nums.data(), nums.size(), pivot, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
