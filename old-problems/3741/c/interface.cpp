#include <vector>

extern "C" {
int minimumDistance(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumDistance(nums.data(), nums.size());
}
