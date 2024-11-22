#include <vector>

extern "C" {
int minimumSubarrayLength(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return minimumSubarrayLength(nums.data(), nums.size(), k);
}
