#include <vector>

extern "C" {
int maxAdjacentDistance(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maxAdjacentDistance(nums.data(), nums.size());
}
