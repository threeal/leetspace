#include <vector>

extern "C" {
bool kLengthApart(int* nums, int numsSize, int k);
}

bool solution_c(std::vector<int> nums, int k) {
  return kLengthApart(nums.data(), nums.size(), k);
}
