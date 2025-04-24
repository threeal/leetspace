#include <vector>

extern "C" {
bool increasingTriplet(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return increasingTriplet(nums.data(), nums.size());
}
