#include <cstring>
#include <vector>

extern "C" {
int* frequencySort(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize;
  int* returnData{frequencySort(nums.data(), nums.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
