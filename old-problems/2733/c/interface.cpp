#include <vector>

extern "C" {
int findNonMinOrMax(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findNonMinOrMax(nums.data(), nums.size());
}
