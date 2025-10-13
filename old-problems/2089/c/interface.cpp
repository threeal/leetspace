#include <cstring>
#include <vector>

extern "C" {
int* targetIndices(int* nums, int numsSize, int target, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int target) {
  int returnSize{};
  int* returnData{targetIndices(nums.data(), nums.size(), target, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
