#include <vector>

extern "C" {
int maximumLength(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return maximumLength(nums.data(), nums.size(), k);
}
