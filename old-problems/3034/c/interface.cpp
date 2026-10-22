#include <vector>

extern "C" {
int countMatchingSubarrays(
    int* nums, int numsSize, int* pattern, int patternSize);
}

int solution_c(std::vector<int> nums, std::vector<int> pattern) {
  return countMatchingSubarrays(
      nums.data(), nums.size(), pattern.data(), pattern.size());
}
