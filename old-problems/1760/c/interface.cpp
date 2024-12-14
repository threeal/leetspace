#include <vector>

extern "C" {
int minimumSize(int* nums, int numsSize, int maxOperations);
}

int solution_c(std::vector<int> nums, int maxOperations) {
  return minimumSize(nums.data(), nums.size(), maxOperations);
}
