#include <vector>

extern "C" {
int minimumOperations(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumOperations(nums.data(), nums.size());
}
