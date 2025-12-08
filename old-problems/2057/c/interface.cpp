#include <vector>

extern "C" {
int smallestEqual(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return smallestEqual(nums.data(), nums.size());
}
