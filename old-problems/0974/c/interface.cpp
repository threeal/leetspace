#include <vector>

extern "C" {
int subarraysDivByK(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return subarraysDivByK(nums.data(), nums.size(), k);
}
