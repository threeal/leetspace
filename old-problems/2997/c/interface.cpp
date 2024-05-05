#include <vector>

extern "C" {
int minOperations(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return minOperations(nums.data(), nums.size(), k);
}
