#include <vector>

extern "C" {
int subarraySum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return subarraySum(nums.data(), nums.size());
}
