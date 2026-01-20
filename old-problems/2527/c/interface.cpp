#include <vector>

extern "C" {
int xorBeauty(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return xorBeauty(nums.data(), nums.size());
}
