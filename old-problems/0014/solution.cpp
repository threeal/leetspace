#include <string>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    for (std::size_t n{0}; strs[0][n] != 0; ++n) {
      for (std::size_t i{1}; i < strs.size(); ++i) {
        if (strs[0][n] != strs[i][n]) {
          strs[0].resize(n);
          return strs[0];
        }
      }
    }
    return strs[0];
  }
};
