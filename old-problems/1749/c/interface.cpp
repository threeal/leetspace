#include <vector>

extern "C" {
int maxAbsoluteSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxAbsoluteSum(nums.data(), nums.size());
}
