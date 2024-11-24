#include <vector>

class Solution {
 public:
  long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
    return matrix.front().front();
  }
};
