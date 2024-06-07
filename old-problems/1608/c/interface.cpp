#include <vector>

extern "C" {
int specialArray(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return specialArray(nums.data(), nums.size());
}
