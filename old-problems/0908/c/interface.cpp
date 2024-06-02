#include <vector>

extern "C" {
int smallestRangeI(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return smallestRangeI(nums.data(), nums.size(), k);
}
