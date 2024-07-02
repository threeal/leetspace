#include <vector>

extern "C" {
int minPatches(int* nums, int numsSize, int n);
}

int solution_c(std::vector<int> nums, int n) {
  return minPatches(nums.data(), nums.size(), n);
}
