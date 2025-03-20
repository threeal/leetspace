#include <vector>

extern "C" {
bool divideArray(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return divideArray(nums.data(), nums.size());
}
