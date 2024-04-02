#include <vector>

extern "C" {
int reductionOperations(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return reductionOperations(nums.data(), nums.size());
}
