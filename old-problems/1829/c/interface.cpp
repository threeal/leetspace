#include <cstring>
#include <vector>

extern "C" {
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums, int maximumBit) {
  int returnSize{};
  const int* returnData = getMaximumXor(
      nums.data(), nums.size(), maximumBit, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
