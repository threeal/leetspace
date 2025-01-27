#include <vector>

extern "C" {
int jump(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return jump(nums.data(), nums.size());
}
