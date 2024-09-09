#include <vector>

class Solution {
 public:
  std::vector<int> minDifference(
      std::vector<int>& /*nums*/, std::vector<std::vector<int>>& queries) {
    return std::vector(queries.size(), -1);
  }
};
