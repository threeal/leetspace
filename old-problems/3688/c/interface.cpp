#include <vector>

extern "C" {
int evenNumberBitwiseORs(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return evenNumberBitwiseORs(nums.data(), nums.size());
}
