#include <vector>

extern "C" {
int triangularSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return triangularSum(nums.data(), nums.size());
}
