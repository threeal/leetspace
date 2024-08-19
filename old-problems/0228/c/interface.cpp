#include <string>
#include <vector>

extern "C" {
char** summaryRanges(int* nums, int numsSize, int* returnSize);
}

std::vector<std::string> solution_c(std::vector<int> nums) {
  int returnSize{};
  const auto returnData = summaryRanges(nums.data(), nums.size(), &returnSize);

  std::vector<std::string> output(returnSize);
  for (int i = returnSize - 1; i >= 0; --i) {
    output[i] = returnData[i];
  }

  return output;
}
