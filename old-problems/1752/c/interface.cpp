#include <vector>

extern "C" {
bool check(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return check(nums.data(), nums.size());
}
