#include <vector>

extern "C" {
bool isGood(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return isGood(nums.data(), nums.size());
}
