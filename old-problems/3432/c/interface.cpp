#include <vector>

extern "C" {
int countPartitions(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countPartitions(nums.data(), nums.size());
}
