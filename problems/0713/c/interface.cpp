#include <vector>

extern "C" {
int numSubarrayProductLessThanK(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return numSubarrayProductLessThanK(nums.data(), nums.size(), k);
}
