#include <vector>

extern "C" {
int findGCD(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findGCD(nums.data(), nums.size());
}
