#include <vector>

extern "C" {
int maxGoodNumber(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxGoodNumber(nums.data(), nums.size());
}
