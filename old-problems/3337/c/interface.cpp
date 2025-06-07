#include <string>
#include <vector>

extern "C" {
int lengthAfterTransformations(char* s, int t, int* nums, int numsSize);
}

int solution_c(std::string s, int t, std::vector<int> nums) {
  return lengthAfterTransformations(s.data(), t, nums.data(), nums.size());
}
