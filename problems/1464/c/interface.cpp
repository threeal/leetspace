#include <vector>

extern "C" {
int maxProduct(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxProduct(nums.data(), nums.size());
}
