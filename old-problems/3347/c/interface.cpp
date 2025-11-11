#include <vector>

extern "C" {
int maxFrequency(int* nums, int numsSize, int k, int numOperations);
}

int solution_c(std::vector<int> nums, int k, int numOperations) {
  return maxFrequency(nums.data(), nums.size(), k, numOperations);
}
