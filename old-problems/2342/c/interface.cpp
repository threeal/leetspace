#include <vector>

extern "C" {
int maximumSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumSum(nums.data(), nums.size());
}
