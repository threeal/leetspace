#include <vector>

extern "C" {
int minimumPrefixLength(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumPrefixLength(nums.data(), nums.size());
}
