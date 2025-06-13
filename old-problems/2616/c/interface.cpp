#include <vector>

extern "C" {
int minimizeMax(int* nums, int numsSize, int p);
}

int solution_c(std::vector<int> nums, int p) {
  return minimizeMax(nums.data(), nums.size(), p);
}
