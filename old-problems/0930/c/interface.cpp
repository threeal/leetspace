#include <vector>

extern "C" {
int numSubarraysWithSum(int* nums, int numsSize, int goal);
}

int solution_c(std::vector<int> nums, int goal) {
  return numSubarraysWithSum(nums.data(), nums.size(), goal);
}
