#include <vector>

extern "C" {
int findLHS(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findLHS(nums.data(), nums.size());
}
