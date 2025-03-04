#include <vector>

extern "C" {
int maxRotateFunction(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxRotateFunction(nums.data(), nums.size());
}
