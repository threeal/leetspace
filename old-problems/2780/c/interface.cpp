#include <vector>

extern "C" {
int minimumIndex(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minimumIndex(nums.data(), nums.size());
}
