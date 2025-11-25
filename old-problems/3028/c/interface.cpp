#include <vector>

extern "C" {
int returnToBoundaryCount(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return returnToBoundaryCount(nums.data(), nums.size());
}
