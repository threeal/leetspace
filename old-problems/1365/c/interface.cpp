#include <cstring>
#include <vector>

extern "C" {
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize{};
  int* returnData{
      smallerNumbersThanCurrent(nums.data(), nums.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
