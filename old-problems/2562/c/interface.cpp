#include <vector>

extern "C" {
long long findTheArrayConcVal(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return findTheArrayConcVal(nums.data(), nums.size());
}
