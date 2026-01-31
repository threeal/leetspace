#include <vector>

extern "C" {
int sumFourDivisors(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return sumFourDivisors(nums.data(), nums.size());
}
