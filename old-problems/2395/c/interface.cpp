#include <vector>

extern "C" {
bool findSubarrays(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return findSubarrays(nums.data(), nums.size());
}
