#include <vector>

extern "C" {
int findMiddleIndex(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findMiddleIndex(nums.data(), nums.size());
}
