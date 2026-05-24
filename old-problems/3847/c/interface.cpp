#include <vector>

extern "C" {
int scoreDifference(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return scoreDifference(nums.data(), nums.size());
}
