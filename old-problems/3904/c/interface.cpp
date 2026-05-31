#include <vector>

extern "C" {
int firstStableIndex(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return firstStableIndex(nums.data(), nums.size(), k);
}
