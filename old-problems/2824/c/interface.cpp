#include <vector>

extern "C" {
int countPairs(int* nums, int numsSize, int target);
}

int solution_c(std::vector<int> nums, int target) {
  return countPairs(nums.data(), nums.size(), target);
}
