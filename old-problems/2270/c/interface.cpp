#include <vector>

extern "C" {
int waysToSplitArray(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return waysToSplitArray(nums.data(), nums.size());
}
