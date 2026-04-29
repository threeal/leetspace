#include <vector>

extern "C" {
int getMinDistance(int* nums, int numsSize, int target, int start);
}

int solution_c(std::vector<int> nums, int target, int start) {
  return getMinDistance(nums.data(), nums.size(), target, start);
}
