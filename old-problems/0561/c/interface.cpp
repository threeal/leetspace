#include <vector>

extern "C" {
int arrayPairSum(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return arrayPairSum(nums.data(), nums.size());
}
