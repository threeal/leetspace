#include <vector>

extern "C" {
int smallestIndex(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return smallestIndex(nums.data(), nums.size());
}
