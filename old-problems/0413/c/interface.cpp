#include <vector>

extern "C" {
int numberOfArithmeticSlices(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return numberOfArithmeticSlices(nums.data(), nums.size());
}
