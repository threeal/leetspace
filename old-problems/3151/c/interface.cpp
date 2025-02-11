#include <vector>

extern "C" {
bool isArraySpecial(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return isArraySpecial(nums.data(), nums.size());
}
