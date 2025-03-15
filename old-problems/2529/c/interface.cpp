#include <vector>

extern "C" {
int maximumCount(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumCount(nums.data(), nums.size());
}
