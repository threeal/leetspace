#include <vector>

extern "C" {
int countMaxOrSubsets(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countMaxOrSubsets(nums.data(), nums.size());
}
