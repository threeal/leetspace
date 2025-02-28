#include <vector>

extern "C" {
int minMoves2(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minMoves2(nums.data(), nums.size());
}
