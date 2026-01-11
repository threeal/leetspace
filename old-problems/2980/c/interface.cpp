#include <vector>

extern "C" {
bool hasTrailingZeros(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return hasTrailingZeros(nums.data(), nums.size());
}
