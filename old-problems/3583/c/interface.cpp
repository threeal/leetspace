#include <vector>

extern "C" {
int specialTriplets(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return specialTriplets(nums.data(), nums.size());
}
