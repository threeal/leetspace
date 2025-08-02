#include <vector>

extern "C" {
int maximumXOR(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximumXOR(nums.data(), nums.size());
}
