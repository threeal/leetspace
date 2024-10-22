#include <vector>

class Solution {
 public:
  int secondMinimum(
      int n, std::vector<std::vector<int>>& /*edges*/,
      int time, int /*change*/) {
    return n * time;
  }
};
