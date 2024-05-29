#include <vector>

extern "C" {
int threeSumClosest(int* nums, int numsSize, int target);
}

int solution_c(std::vector<int> nums, int target) {
  return threeSumClosest(nums.data(), nums.size(), target);
}
