#include <vector>

extern "C" {
long long findScore(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return findScore(nums.data(), nums.size());
}
