#include <vector>

class Solution {
 public:
  std::vector<int> findDegrees(std::vector<std::vector<int>>& matrix) {
    std::vector<int> degrees(matrix.size(), 0);
    for (std::size_t i{0}; i < matrix.size(); ++i) {
      for (const int val : matrix[i]) {
        if (val == 1) ++degrees[i];
      }
    }
    return degrees;
  }
};
