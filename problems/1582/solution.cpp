#include <vector>

class Solution {
 public:
  int numSpecial(std::vector<std::vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();

    std::vector<int> rows(m, -1);
    std::vector<int> cols(n, -1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          rows[i] = rows[i] == -1 ? j : -2;
          cols[j] = cols[j] == -1 ? i : -2;
        }
      }
    }

    int specials = 0;
    for (int i = 0; i < m; ++i) {
      if (rows[i] >= 0 && cols[rows[i]] == i) ++specials;
    }

    return specials;
  }
};
