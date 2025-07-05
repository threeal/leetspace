#include <cstring>
#include <vector>

extern "C" {
int duplicateNumbersXOR(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return duplicateNumbersXOR(nums.data(), nums.size());
}
