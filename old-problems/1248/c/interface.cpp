#include <vector>

extern "C" {
int numberOfSubarrays(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return numberOfSubarrays(nums.data(), nums.size(), k);
}
