#include <vector>

extern "C" {
int missingNumber(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return missingNumber(nums.data(), nums.size());
}
