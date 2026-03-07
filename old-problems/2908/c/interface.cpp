#include <vector>

extern "C" {
int minimumSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumSum(nums.data(), nums.size());
}
