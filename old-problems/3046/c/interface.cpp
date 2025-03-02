#include <vector>

extern "C" {
bool isPossibleToSplit(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return isPossibleToSplit(nums.data(), nums.size());
}
