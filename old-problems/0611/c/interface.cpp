#include <vector>

extern "C" {
int triangleNumber(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return triangleNumber(nums.data(), nums.size());
}
