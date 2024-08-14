#include <vector>

extern "C" {
int minSwaps(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minSwaps(nums.data(), nums.size());
}
