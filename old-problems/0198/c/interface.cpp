#include <vector>

extern "C" {
int rob(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return rob(nums.data(), nums.size());
}
