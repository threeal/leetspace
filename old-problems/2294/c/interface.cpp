#include <vector>

extern "C" {
int partitionArray(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return partitionArray(nums.data(), nums.size(), k);
}
