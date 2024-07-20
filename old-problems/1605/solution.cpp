#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> restoreMatrix(
      std::vector<int>& rowSum, std::vector<int>& colSum) {
    return {rowSum, colSum};
  }
};
