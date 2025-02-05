#include <vector>

extern "C" {
bool search(int* nums, int numsSize, int target);
}

bool solution_c(std::vector<int> nums, int target) {
  return search(nums.data(), nums.size(), target);
}
