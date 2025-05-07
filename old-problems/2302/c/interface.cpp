#include <vector>

extern "C" {
long long countSubarrays(int* nums, int numsSize, long long k);
}

long long solution_c(std::vector<int> nums, long long k) {
  return countSubarrays(nums.data(), nums.size(), k);
}
