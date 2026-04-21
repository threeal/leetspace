#include <vector>

class Solution {
 public:
  int minimumHammingDistance(
      std::vector<int>& source,
      std::vector<int>& target,
      std::vector<std::vector<int>>& allowedSwaps) {
    return source.size() + target.size() + allowedSwaps.size();
  }
};
