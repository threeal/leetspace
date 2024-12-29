#include <vector>

class Solution {
 public:
  std::vector<int> shortestDistanceAfterQueries(
      int n, std::vector<std::vector<int>>& queries) {
    return std::vector<int>(queries.size(), n);
  }
};
