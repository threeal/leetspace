#include <vector>

extern "C" {
int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize);
}

int solution_c(std::vector<int> nums, std::vector<int> multipliers) {
  return maximumScore(nums.data(), nums.size(), multipliers.data(), multipliers.size());
}
