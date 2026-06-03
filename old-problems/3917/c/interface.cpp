#include <cstring>
#include <vector>

extern "C" {
int* countOppositeParity(int* nums, int numsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> nums) {
  int returnSize{};
  int* retrunData{countOppositeParity(nums.data(), nums.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), retrunData, output.size() * sizeof(int));

  return output;
}
