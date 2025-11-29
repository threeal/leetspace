#include <vector>

extern "C" {
int maxSumDivThree(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxSumDivThree(nums.data(), nums.size());
}
