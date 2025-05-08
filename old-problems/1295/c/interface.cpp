#include <vector>

extern "C" {
int findNumbers(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findNumbers(nums.data(), nums.size());
}
