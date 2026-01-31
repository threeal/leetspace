#include <vector>

extern "C" {
int countPartitions(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return countPartitions(nums.data(), nums.size(), k);
}
