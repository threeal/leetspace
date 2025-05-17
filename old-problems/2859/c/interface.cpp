#include <vector>

extern "C" {
int sumIndicesWithKSetBits(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return sumIndicesWithKSetBits(nums.data(), nums.size(), k);
}
