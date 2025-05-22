#include <vector>

extern "C" {
double minimumAverage(int* nums, int numsSize);
}

double solution_c(std::vector<int> nums) {
  return minimumAverage(nums.data(), nums.size());
}
