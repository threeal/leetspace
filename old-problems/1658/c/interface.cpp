#include <vector>

extern "C" {
int minOperations(int* nums, int numsSize, int x);
}

int solution_c(std::vector<int> nums, int x) {
  return minOperations(nums.data(), nums.size(), x);
}
