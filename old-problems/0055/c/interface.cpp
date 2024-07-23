#include <vector>

extern "C" {
bool canJump(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return canJump(nums.data(), nums.size());
}
