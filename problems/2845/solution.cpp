#include <unordered_map>
#include <vector>

class Solution {
 public:
  long long countInterestingSubarrays(
      std::vector<int>& nums, int modulo, int k) {
    long long count{0}, interesting{0};
    std::unordered_map<int, long long> modCounts{};
    modCounts[0] = 1;

    for (const int num : nums) {
      if (num % modulo == k) {
        interesting = (interesting + 1) % modulo;
      }
      const int prev = (interesting + modulo - k) % modulo;
      count += modCounts[prev];
      ++modCounts[interesting];
    }

    return count;
  }
};
