#include <vector>

extern "C" {
bool canAliceWin(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return canAliceWin(nums.data(), nums.size());
}
