#include <vector>

extern "C" {
int singleNumber(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return singleNumber(nums.data(), nums.size());
}
