#include <vector>

extern "C" {
int countPairs(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return countPairs(nums.data(), nums.size(), k);
}
