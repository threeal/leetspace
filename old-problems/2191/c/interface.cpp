#include <cstring>
#include <vector>

extern "C" {
int* sortJumbled(
    int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> mapping, std::vector<int> nums) {
  int returnSize{};
  int* returnData{
      sortJumbled(
          mapping.data(), mapping.size(), nums.data(), nums.size(),
          &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
