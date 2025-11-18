#include <vector>

class Solution {
 public:
  std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat) {
    int maxI{0}, maxCount{0};
    for (std::size_t i{0}; i < mat.size(); ++i) {
      int count{0};
      for (std::size_t j{0}; j < mat[i].size(); ++j) {
        if (mat[i][j] == 1) ++count;
      }

      if (count > maxCount) {
        maxI = i;
        maxCount = count;
      }
    }

    return {maxI, maxCount};
  }
};
