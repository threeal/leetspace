#include <vector>

extern "C" {
int minimumDifference(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return minimumDifference(nums.data(), nums.size(), k);
}
