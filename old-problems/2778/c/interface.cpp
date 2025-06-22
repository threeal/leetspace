#include <vector>

extern "C" {
int sumOfSquares(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return sumOfSquares(nums.data(), nums.size());
}
