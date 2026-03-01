#include <vector>

extern "C" {
int minimumCost(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumCost(nums.data(), nums.size());
}
