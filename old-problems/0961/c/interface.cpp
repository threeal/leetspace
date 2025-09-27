#include <vector>

extern "C" {
int repeatedNTimes(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return repeatedNTimes(nums.data(), nums.size());
}
