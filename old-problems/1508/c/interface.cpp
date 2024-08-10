#include <vector>

extern "C" {
int rangeSum(int* nums, int numsSize, int n, int left, int right);
}

int solution_c(std::vector<int> nums, int n, int left, int right) {
  return rangeSum(nums.data(), nums.size(), n, left, right);
}
