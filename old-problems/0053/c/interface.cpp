#include <vector>

extern "C" {
int maxSubArray(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxSubArray(nums.data(), nums.size());
}
