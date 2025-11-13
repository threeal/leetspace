#include <cstring>
#include <vector>

extern "C" {
int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int k, int x) {
  int returnSize{};
  int* returnData{findXSum(nums.data(), nums.size(), k, x, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
