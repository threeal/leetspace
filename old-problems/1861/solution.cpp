#include <vector>

class Solution {
 public:
  std::vector<std::vector<char>> rotateTheBox(
      std::vector<std::vector<char>>& box) {
    const int m = box.size();
    const int n = box.front().size();

    std::vector<std::vector<char>> out(n, std::vector<char>(m));

    for (int i{0}; i < m; ++i) {
      for (int j{n - 1}, jj{n - 1}; j >= 0; --j) {
        switch (box[m - i - 1][j]) {
          case '#':
            out[j][i] = '.';
            out[jj][i] = '#';
            --jj;
            break;

          case '*':
            out[j][i] = '*';
            jj = j - 1;
            break;

          case '.':
            out[j][i] = '.';
        }
      }
    }

    return out;
  }
};
