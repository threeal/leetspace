#include <vector>

extern "C" {
int unequalTriplets(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return unequalTriplets(nums.data(), nums.size());
}
