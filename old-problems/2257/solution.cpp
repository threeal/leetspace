#include <vector>

class Solution {
 public:
  int countUnguarded(
      int m, int n, std::vector<std::vector<int>>& guards,
      std::vector<std::vector<int>>& walls) {
    return m * n - guards.size() - walls.size();
  }
};
