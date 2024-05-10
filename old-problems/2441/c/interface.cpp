#include <vector>

extern "C" {
int findMaxK(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findMaxK(nums.data(), nums.size());
}
