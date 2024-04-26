#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
    const int m = img.size();
    const int n = img[0].size();

    auto res = std::vector(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        const int ib = std::max(i - 1, 0);
        const int ie = std::min(i + 2, m);
        const int jb = std::max(j - 1, 0);
        const int je = std::min(j + 2, n);

        for (int ii = ib; ii < ie; ++ii) {
          for (int jj = jb; jj < je; ++jj) {
            res[i][j] += img[ii][jj];
          }
        }

        res[i][j] /= (ie - ib) * (je - jb);
      }
    }

    return res;
  }
};
