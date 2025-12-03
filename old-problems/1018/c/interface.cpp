#include <vector>

extern "C" {
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize);
}

std::vector<bool> solution_c(std::vector<int> nums) {
  int returnSize{};
  bool* returnData{prefixesDivBy5(nums.data(), nums.size(), &returnSize)};

  std::vector<bool> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) output[i] = returnData[i];

  return output;
}
