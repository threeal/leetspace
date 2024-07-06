#include <vector>

extern "C" {
int maximumJumps(int* nums, int numsSize, int target);
}

int solution_c(std::vector<int> nums, int target) {
  return maximumJumps(nums.data(), nums.size(), target);
}
