#include <vector>

extern "C" {
int subsetXORSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return subsetXORSum(nums.data(), nums.size());
}
