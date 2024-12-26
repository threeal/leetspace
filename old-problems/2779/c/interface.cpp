#include <vector>

extern "C" {
int maximumBeauty(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return maximumBeauty(nums.data(), nums.size(), k);
}
