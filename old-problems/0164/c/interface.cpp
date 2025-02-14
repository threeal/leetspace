#include <vector>

extern "C" {
int maximumGap(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumGap(nums.data(), nums.size());
}
