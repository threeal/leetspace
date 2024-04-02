#include <vector>

extern "C" {
int maxProductDifference(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxProductDifference(nums.data(), nums.size());
}
