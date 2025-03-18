#include <vector>

extern "C" {
int minCapability(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return minCapability(nums.data(), nums.size(), k);
}
