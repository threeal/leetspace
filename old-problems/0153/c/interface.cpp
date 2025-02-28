#include <vector>

extern "C" {
int findMin(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findMin(nums.data(), nums.size());
}
