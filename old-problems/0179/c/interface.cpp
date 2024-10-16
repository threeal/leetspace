#include <string>
#include <vector>

extern "C" {
char* largestNumber(int* nums, int numsSize);
}

std::string solution_c(std::vector<int> nums) {
  return largestNumber(nums.data(), nums.size());
}
