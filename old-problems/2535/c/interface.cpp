#include <vector>

extern "C" {
int differenceOfSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return differenceOfSum(nums.data(), nums.size());
}
