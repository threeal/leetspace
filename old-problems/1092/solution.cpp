#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string shortestCommonSupersequence(std::string str1, std::string str2) {
    std::vector<std::vector<int>> lcs(
        str1.size() + 1, std::vector(str2.size() + 1, 0));

    for (std::size_t i{1}; i <= str1.size(); ++i) {
      for (std::size_t j{1}; j <= str2.size(); ++j) {
        if (str1[i - 1] == str2[j - 1]) {
          lcs[i][j] = lcs[i - 1][j - 1] + 1;
        } else {
          lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
        }
      }
    }

    std::string output(str1.size() + str2.size() - lcs.back().back(), 'x');
    std::size_t i{str1.size()}, j{str2.size()}, k{output.size()};
    while (i > 0 && j > 0) {
      if (str1[i - 1] == str2[j - 1]) {
        output[--k] = str1[--i];
        --j;
      } else if (lcs[i - 1][j] >= lcs[i][j - 1]) {
        output[--k] = str1[--i];
      } else {
        output[--k] = str2[--j];
      }
    }

    while (i > 0) output[--k] = str1[--i];
    while (j > 0) output[--k] = str2[--j];

    return output;
  }
};
