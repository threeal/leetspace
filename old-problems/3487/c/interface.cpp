#include <vector>

extern "C" {
int maxSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxSum(nums.data(), nums.size());
}
