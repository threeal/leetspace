#include <vector>

extern "C" {
long long countSubarrays(int* nums, int numsSize, int minK, int maxK);
}

long long solution_c(std::vector<int> nums, int minK, int maxK) {
  return countSubarrays(nums.data(), nums.size(), minK, maxK);
}
