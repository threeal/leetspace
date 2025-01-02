#include <vector>

extern "C" {
long long maxKelements(int* nums, int numsSize, int k);
}

long long solution_c(std::vector<int> nums, int k) {
  return maxKelements(nums.data(), nums.size(), k);
}
