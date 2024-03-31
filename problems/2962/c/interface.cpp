#include <vector>

extern "C" {
long long countSubarrays(int* nums, int numsSize, int k);
}

long long solution_c(std::vector<int> nums, int k) {
  return countSubarrays(nums.data(), nums.size(), k);
}
