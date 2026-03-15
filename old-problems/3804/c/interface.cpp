#include <vector>

extern "C" {
int centeredSubarrays(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return centeredSubarrays(nums.data(), nums.size());
}
