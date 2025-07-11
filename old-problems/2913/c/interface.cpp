#include <vector>

extern "C" {
int sumCounts(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return sumCounts(nums.data(), nums.size());
}
