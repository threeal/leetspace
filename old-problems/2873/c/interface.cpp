#include <cstring>
#include <vector>

extern "C" {
long long maximumTripletValue(int* nums, int numsSize);
}

long long solution_c(std::vector<int> nums) {
  return maximumTripletValue(nums.data(), nums.size());
}
