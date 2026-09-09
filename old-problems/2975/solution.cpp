#include <vector>

class Solution {
 public:
  int maximizeSquareArea(
      int m, int n, std::vector<int>& hFences, std::vector<int>& vFences) {
    return m + n + hFences.size() + vFences.size();
  }
};
