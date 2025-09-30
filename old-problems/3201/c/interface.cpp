#include <vector>

extern "C" {
int maximumLength(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumLength(nums.data(), nums.size());
}
