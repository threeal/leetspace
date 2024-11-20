#include <vector>

extern "C" {
bool canSortArray(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return canSortArray(nums.data(), nums.size());
}
