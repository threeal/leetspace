#include <vector>

extern "C" {
int sumOfEncryptedInt(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return sumOfEncryptedInt(nums.data(), nums.size());
}
