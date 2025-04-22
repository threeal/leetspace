#include <cstring>
#include <vector>

extern "C" {
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize;
  const int* returnData{
      findDisappearedNumbers(nums.data(), nums.size(), &returnSize)};

  nums.resize(returnSize);
  std::memcpy(nums.data(), returnData, sizeof(int) * returnSize);

  return nums;
}
