#include <string>
#include <vector>

extern "C" {
char* triangleType(int* nums, int numsSize);
}

std::string solution_c(std::vector<int> nums) {
  return triangleType(nums.data(), nums.size());
}
