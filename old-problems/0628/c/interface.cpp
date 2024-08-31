#include <vector>

extern "C" {
int maximumProduct(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumProduct(nums.data(), nums.size());
}
