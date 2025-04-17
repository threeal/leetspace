#include <vector>

extern "C" {
int maximumScore(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return maximumScore(nums.data(), nums.size(), k);
}
