#include <vector>

extern "C" {
int countCompleteSubarrays(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countCompleteSubarrays(nums.data(), nums.size());
}
