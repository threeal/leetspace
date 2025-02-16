#include <vector>

extern "C" {
long long countBadPairs(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return countBadPairs(nums.data(), nums.size());
}
