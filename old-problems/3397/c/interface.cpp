#include <vector>

extern "C" {
int maxDistinctElements(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return maxDistinctElements(nums.data(), nums.size(), k);
}
