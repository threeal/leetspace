#include <vector>

extern "C" {
int numIdenticalPairs(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return numIdenticalPairs(nums.data(), nums.size());
}
