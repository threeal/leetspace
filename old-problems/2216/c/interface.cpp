#include <vector>

extern "C" {
int minDeletion(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return minDeletion(nums.data(), nums.size());
}
