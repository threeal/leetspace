#include <vector>

extern "C" {
int countHillValley(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countHillValley(nums.data(), nums.size());
}
