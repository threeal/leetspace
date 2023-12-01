#include <string>

class Solution {
 public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;

    auto res = s;
    int n = s.size();
    int rn = (numRows - 1) * 2;

    int i = -1;

    for (int j = 0; j < n; j += rn) {
      res[++i] = s[j];
    }

    for (int r = 1; r < numRows - 1; ++r) {
      auto rj = rn - (2 * r);
      for (int j = r; j < n; j += rn) {
        res[++i] = s[j];
        if (j + rj < n) {
          res[++i] = s[j + rj];
        }
      }
    }

    for (int j = numRows - 1; j < n; j += rn) {
      res[++i] = s[j];
    }

    return res;
  }
};
