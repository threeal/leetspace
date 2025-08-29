#include <vector>

class Solution {
 public:
  long long maxSubarrays(
      int n, std::vector<std::vector<int>>& conflictingPairs) {
    return n + conflictingPairs.size();
  }
};
