#include <vector>

extern "C" {
int findDuplicate(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return findDuplicate(nums.data(), nums.size());
}
