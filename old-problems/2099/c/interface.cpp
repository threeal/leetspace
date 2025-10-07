#include <cstring>
#include <vector>

extern "C" {
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int k) {
  int returnSize{};
  int* returnData{maxSubsequence(nums.data(), nums.size(), k, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
