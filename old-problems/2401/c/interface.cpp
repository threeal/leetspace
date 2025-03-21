#include <vector>

extern "C" {
int longestNiceSubarray(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return longestNiceSubarray(nums.data(), nums.size());
}
