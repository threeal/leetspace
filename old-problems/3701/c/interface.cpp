
#include <vector>

extern "C" {
int alternatingSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return alternatingSum(nums.data(), nums.size());
}
