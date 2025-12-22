#include <string>
#include <vector>

class Solution {
 public:
  int minDeletionSize(std::vector<std::string>& strs) {
    int deletions{0};
    std::vector<bool> isValids(strs[0].size(), false);
    std::size_t validLefts{strs.size() - 1};

    for (std::size_t i{0}; i < strs[0].size() && validLefts > 0; ++i) {
      std::size_t j{1};
      while (j < strs.size() &&
             (isValids[j] || (strs[j - 1][i] <= strs[j][i]))) ++j;

      if (j == strs.size()) {
        for (std::size_t j{1}; j < strs.size(); ++j) {
          if (!isValids[j] && strs[j - 1][i] < strs[j][i]) {
            isValids[j] = true;
            --validLefts;
          }
        }
      } else {
        ++deletions;
      }
    }

    return deletions;
  }
};
