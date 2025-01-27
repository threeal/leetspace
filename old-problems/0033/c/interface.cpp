#include <vector>

extern "C" {
int search(int* nums, int numsSize, int target);
}

int solution_c(std::vector<int> nums, int target) {
  return search(nums.data(), nums.size(), target);
}
