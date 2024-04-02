#include <vector>

extern "C" {
int majorityElement(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return majorityElement(nums.data(), nums.size());
}
