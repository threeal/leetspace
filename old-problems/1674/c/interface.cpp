#include <vector>

extern "C" {
int minMoves(int* nums, int numsSize, int limit);
}

int solution_c(std::vector<int> nums, int limit) {
  return minMoves(nums.data(), nums.size(), limit);
}
