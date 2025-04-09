#include <string>
#include <vector>

class Solution {
 public:
  bool isScramble(std::string s1, std::string s2) {
    std::vector<std::vector<std::vector<bool>>> valid(
        s1.size(), std::vector(s1.size(), std::vector(s1.size() + 1, false)));

    for (std::size_t i1{0}; i1 < s1.size(); ++i1) {
      for (std::size_t i2{0}; i2 < s1.size(); ++i2) {
        valid[i1][i2][1] = s1[i1] == s2[i2];
      }
    }

    for (std::size_t n{2}; n <= s1.size(); ++n) {
      const std::size_t r{s1.size() - n};
      for (std::size_t i1{0}; i1 <= r; ++i1) {
        for (std::size_t i2{0}; i2 <= r; ++i2) {
          for (std::size_t j{1}; j < n; ++j) {
            if (valid[i1][i2][j] && valid[i1 + j][i2 + j][n - j]) {
              valid[i1][i2][n] = true;
              break;
            }
            if (valid[i1][i2 + n - j][j] && valid[i1 + j][i2][n - j]) {
              valid[i1][i2][n] = true;
              break;
            }
          }
        }
      }
    }

    return valid[0][0][s1.size()];
  }
};
