#include <vector>

extern "C" {
long long countFairPairs(int* nums, int numsSize, int lower, int upper);
}

long long solution_c(std::vector<int> nums, int lower, int upper) {
  return countFairPairs(nums.data(), nums.size(), lower, upper);
}
