#include <vector>

extern "C" {
int arithmeticTriplets(int* nums, int numsSize, int diff);
}

int solution_c(std::vector<int> nums, int diff) {
  return arithmeticTriplets(nums.data(), nums.size(), diff);
}
