#include <vector>

extern "C" {
int minPairSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minPairSum(nums.data(), nums.size());
}
