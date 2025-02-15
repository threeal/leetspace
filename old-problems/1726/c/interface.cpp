#include <vector>

extern "C" {
int tupleSameProduct(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return tupleSameProduct(nums.data(), nums.size());
}
