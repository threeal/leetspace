#include <vector>

extern "C" {
int countKDifference(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return countKDifference(nums.data(), nums.size(), k);
}
