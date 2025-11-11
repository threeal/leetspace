#include <vector>

extern "C" {
int sumDivisibleByK(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return sumDivisibleByK(nums.data(), nums.size(), k);
}
