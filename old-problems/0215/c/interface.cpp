#include <vector>

extern "C" {
int findKthLargest(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return findKthLargest(nums.data(), nums.size(), k);
}
