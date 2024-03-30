#include <vector>

extern "C" {
int firstMissingPositive(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return firstMissingPositive(nums.data(), nums.size());
}
