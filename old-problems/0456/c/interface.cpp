#include <vector>

extern "C" {
bool find132pattern(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return find132pattern(nums.data(), nums.size());
}
