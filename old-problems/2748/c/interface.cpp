#include <vector>

extern "C" {
int countBeautifulPairs(int* nums, int numsSize);
}

int solution_c(std::vector<int> nums) {
  return countBeautifulPairs(nums.data(), nums.size());
}
