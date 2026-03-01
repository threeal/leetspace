#include <vector>

extern "C" {
int longestOnes(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return longestOnes(nums.data(), nums.size(), k);
}
