#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* /*head*/) {
    return std::vector(m, std::vector(n, -1));
  }
};
