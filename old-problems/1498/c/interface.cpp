#include <vector>

extern "C" {
int numSubseq(int* nums, int numsSize, int target);
}

int solution_c(std::vector<int> nums, int target) {
  return numSubseq(nums.data(), nums.size(), target);
}
