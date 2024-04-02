#include <cstring>
#include <vector>

extern "C" {
long long largestPerimeter(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return largestPerimeter(nums.data(), nums.size());
}
