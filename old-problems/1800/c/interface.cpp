#include <vector>

extern "C" {
int maxAscendingSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxAscendingSum(nums.data(), nums.size());
}
