#include <vector>

extern "C" {
int findFinalValue(int* nums, int numsSize, int original);
}

int solution_c(std::vector<int> nums, int original) {
  return findFinalValue(nums.data(), nums.size(), original);
}
