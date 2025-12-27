#include <vector>

extern "C" {
int maximizeExpressionOfThree(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return maximizeExpressionOfThree(nums.data(), nums.size());
}
