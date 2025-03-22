#include <vector>

extern "C" {
int minOperations(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minOperations(nums.data(), nums.size());
}
