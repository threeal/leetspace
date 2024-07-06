#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> diagonalSort(
      std::vector<std::vector<int>>& mat) {
    const int h = mat.size();
    if (h == 1) return mat;

    const int w = mat.front().size();
    if (w == 1) return mat;

    std::vector<int> tempArr(std::max(h, w));

    for (int x = w - 1; x >= 0; --x) {
      int n{std::min(w - x, h)};
      int i{n};
      while (--i >= 0) tempArr[i] = mat[i][x + i];

      std::sort(tempArr.begin(), tempArr.begin() + n);

      i = n;
      while (--i >= 0) mat[i][x + i] = tempArr[i];
    }

    for (int y = h - 1; y > 0; --y) {
      int n{std::min(h - y, w)};
      int i{n};
      while (--i >= 0) tempArr[i] = mat[y + i][i];

      std::sort(tempArr.begin(), tempArr.begin() + n);

      i = n;
      while (--i >= 0) mat[y + i][i] = tempArr[i];
    }

    return mat;
  }
};
