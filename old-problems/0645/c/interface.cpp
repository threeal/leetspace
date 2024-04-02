#include <cstdlib>
#include <cstring>
#include <vector>

extern "C" {
int* findErrorNums(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize;
  int* returnData = findErrorNums(nums.data(), nums.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));
  free(returnData);

  return output;
}
