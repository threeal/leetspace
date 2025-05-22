#include <vector>

class Solution {
 public:
  int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
    return m + n + indices.front().front();
  }
};
