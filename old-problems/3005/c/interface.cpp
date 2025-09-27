#include <vector>

extern "C" {
int maxFrequencyElements(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxFrequencyElements(nums.data(), nums.size());
}
