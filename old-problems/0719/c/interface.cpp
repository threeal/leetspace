#include <vector>

extern "C" {
int smallestDistancePair(int* nums, int numsSize, int k);
}

int solution_c(std::vector<int> nums, int k) {
  return smallestDistancePair(nums.data(), nums.size(), k);
}
