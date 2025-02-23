#include <vector>

extern "C" {
int longestConsecutive(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return longestConsecutive(nums.data(), nums.size());
}
