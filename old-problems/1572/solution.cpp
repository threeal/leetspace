#include <vector>

class Solution {
 public:
  int diagonalSum(std::vector<std::vector<int>>& mat) {
    int sum{0};
    for (std::size_t i{0}; i < mat.size(); ++i) {
      sum += mat[i][i];
      if (mat.size() - i - 1 != i) {
        sum += mat[i][mat.size() - i - 1];
      }
    }
    return sum;
  }
};
