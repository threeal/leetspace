#include <vector>

extern "C" {
int countValidSelections(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countValidSelections(nums.data(), nums.size());
}
