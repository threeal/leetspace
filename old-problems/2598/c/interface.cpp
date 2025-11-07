#include <vector>

extern "C" {
int findSmallestInteger(int* nums, int numsSize, int value);
}

int solution_c(std::vector<int> nums, int value) {
  return findSmallestInteger(nums.data(), nums.size(), value);
}
