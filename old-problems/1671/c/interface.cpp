#include <vector>

extern "C" {
int minimumMountainRemovals(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumMountainRemovals(nums.data(), nums.size());
  ;
}
