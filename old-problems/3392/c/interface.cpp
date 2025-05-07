#include <vector>

extern "C" {
int countSubarrays(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countSubarrays(nums.data(), nums.size());
}
