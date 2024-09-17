#include <vector>

extern "C" {
long long zeroFilledSubarray(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return zeroFilledSubarray(nums.data(), nums.size());
}
