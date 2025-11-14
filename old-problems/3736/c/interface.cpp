#include <vector>

extern "C" {
int minMoves(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minMoves(nums.data(), nums.size());
}
