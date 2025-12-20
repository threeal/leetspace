#include <vector>

extern "C" {
int findKOr(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return findKOr(nums.data(), nums.size(), k);
}
