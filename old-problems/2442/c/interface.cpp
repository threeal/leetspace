#include <vector>

extern "C" {
int countDistinctIntegers(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countDistinctIntegers(nums.data(), nums.size());
}
