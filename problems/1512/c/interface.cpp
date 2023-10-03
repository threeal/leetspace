#include <vector>

extern "C" {
int numIdenticalPairs(int* nums, int numsSize);
}

int solution_c(const std::vector<int>& nums) {
  return numIdenticalPairs(const_cast<int*>(nums.data()), nums.size());
}
