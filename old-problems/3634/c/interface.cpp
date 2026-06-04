#include <vector>

extern "C" {
int minRemoval(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return minRemoval(nums.data(), nums.size(), k);
}
