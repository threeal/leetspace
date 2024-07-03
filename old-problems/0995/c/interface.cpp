#include <vector>

extern "C" {
int minKBitFlips(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return minKBitFlips(nums.data(), nums.size(), k);
}
