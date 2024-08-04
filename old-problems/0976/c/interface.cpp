#include <vector>

extern "C" {
int largestPerimeter(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return largestPerimeter(nums.data(), nums.size());
}
