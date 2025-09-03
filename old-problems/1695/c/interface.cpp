#include <vector>

extern "C" {
int maximumUniqueSubarray(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumUniqueSubarray(nums.data(), nums.size());
}
