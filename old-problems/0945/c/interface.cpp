#include <vector>

extern "C" {
int minIncrementForUnique(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minIncrementForUnique(nums.data(), nums.size());
}
