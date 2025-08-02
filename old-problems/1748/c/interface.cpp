#include <vector>

extern "C" {
int sumOfUnique(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return sumOfUnique(nums.data(), nums.size());
}
