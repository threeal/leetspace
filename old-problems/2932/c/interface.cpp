#include <vector>

extern "C" {
int maximumStrongPairXor(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumStrongPairXor(nums.data(), nums.size());
}
