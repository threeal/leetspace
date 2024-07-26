#include <vector>

extern "C" {
int minDifference(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minDifference(nums.data(), nums.size());
}
