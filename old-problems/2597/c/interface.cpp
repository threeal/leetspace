#include <vector>

extern "C" {
int beautifulSubsets(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return beautifulSubsets(nums.data(), nums.size(), k);
}
