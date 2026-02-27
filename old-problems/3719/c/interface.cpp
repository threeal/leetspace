#include <vector>

extern "C" {
int longestBalanced(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return longestBalanced(nums.data(), nums.size());
}
