#include <vector>

extern "C" {
long long maxTotalValue(int* nums, int numsSize, int k);
}

long long solution_c(std::vector<int> nums, int k) {
  return maxTotalValue(nums.data(), nums.size(), k);
}
