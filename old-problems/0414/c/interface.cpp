#include <vector>

extern "C" {
int thirdMax(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return thirdMax(nums.data(), nums.size());
}
