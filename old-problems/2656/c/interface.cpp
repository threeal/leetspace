#include <vector>

extern "C" {
int maximizeSum(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return maximizeSum(nums.data(), nums.size(), k);
}
