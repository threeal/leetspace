#include <vector>

extern "C" {
int sumOfGoodNumbers(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return sumOfGoodNumbers(nums.data(), nums.size(), k);
}
