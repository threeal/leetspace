#include <vector>

extern "C" {
int longestSquareStreak(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return longestSquareStreak(nums.data(), nums.size());
}
