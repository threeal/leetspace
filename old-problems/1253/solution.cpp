#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> reconstructMatrix(
      int upper, int lower, std::vector<int>& colsum) {
    std::vector<std::vector<int>> mat(2, std::vector<int>(colsum.size(), 0));

    for (int i = colsum.size() - 1; i >= 0; --i) {
      if (colsum[i] == 2) {
        if (lower > 0 && upper > 0) {
          mat[1][i] = 1;
          mat[0][i] = 1;
          --lower;
          --upper;
        } else {
          return {};
        }
      }
    }

    for (int i = colsum.size() - 1; i >= 0; --i) {
      if (colsum[i] == 1) {
        if (lower > 0) {
          mat[1][i] = 1;
          --lower;
        } else if (upper > 0) {
          mat[0][i] = 1;
          --upper;
        } else {
          return {};
        }
      }
    }

    if (upper > 0 || lower > 0) return {};
    return mat;
  }
};
