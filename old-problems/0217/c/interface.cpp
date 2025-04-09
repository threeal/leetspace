#include <vector>

extern "C" {
bool containsDuplicate(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return containsDuplicate(nums.data(), nums.size());
}
