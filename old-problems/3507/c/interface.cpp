#include <vector>

extern "C" {
int minimumPairRemoval(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumPairRemoval(nums.data(), nums.size());
}
