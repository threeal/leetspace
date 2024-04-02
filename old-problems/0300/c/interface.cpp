#include <vector>

extern "C" {
int lengthOfLIS(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return lengthOfLIS(nums.data(), nums.size());
}
