#include <algorithm>
#include <functional>
#include <string>

class Solution {
 public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    auto cache = std::vector(text1.size(), std::vector(text2.size(), -1));

    const std::function<int(std::size_t i1, std::size_t i2)> fn = [&](std::size_t i1, std::size_t i2) {
      if (i1 >= text1.size() || i2 >= text2.size()) return 0;

      if (cache[i1][i2] < 0) {
        if (text1[i1] == text2[i2]) {
          cache[i1][i2] = std::max(
              1 + fn(i1 + 1, i2 + 1),
              std::max(
                  fn(i1 + 1, i2),
                  fn(i1, i2 + 1)));
        } else {
          cache[i1][i2] = std::max(
              fn(i1 + 1, i2),
              fn(i1, i2 + 1));
        }
      }

      return cache[i1][i2];
    };

    return fn(0, 0);
  }
};
