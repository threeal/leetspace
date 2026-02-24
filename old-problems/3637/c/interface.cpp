#include <vector>

extern "C" {
bool isTrionic(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return isTrionic(nums.data(), nums.size());
}
