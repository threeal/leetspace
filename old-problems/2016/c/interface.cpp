#include <vector>

extern "C" {
int maximumDifference(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumDifference(nums.data(), nums.size());
}
