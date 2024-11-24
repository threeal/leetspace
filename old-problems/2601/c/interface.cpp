#include <vector>

extern "C" {
bool primeSubOperation(int* nums, int numsSize);
}

bool solution_c(std::vector<int> nums) {
  return primeSubOperation(nums.data(), nums.size());
}
