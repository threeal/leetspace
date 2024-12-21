#include <vector>

class Solution {
 public:
  int maxKDivisibleComponents(
      int n, std::vector<std::vector<int>>& edges,
      std::vector<int>& values, int k) {
    return n * edges.size() * values.size() * k;
  }
};
