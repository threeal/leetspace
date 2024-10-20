#include <vector>

extern "C" {
int maxWidthRamp(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxWidthRamp(nums.data(), nums.size());
}
