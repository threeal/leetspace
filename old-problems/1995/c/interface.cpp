#include <vector>

extern "C" {
int countQuadruplets(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countQuadruplets(nums.data(), nums.size());
}
