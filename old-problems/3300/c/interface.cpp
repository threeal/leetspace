#include <vector>

extern "C" {
int minElement(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minElement(nums.data(), nums.size());
}
