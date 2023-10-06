#include <interface.hpp>
#include <vector>

extern "C" {
int numIdenticalPairs(int* nums, int numsSize);
}

template <>
int solution_c(const std::vector<int>& nums) {
  auto nums_copy = nums;
  return numIdenticalPairs(nums_copy.data(), nums_copy.size());
}
