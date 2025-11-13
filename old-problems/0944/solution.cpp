#include <string>
#include <vector>

class Solution {
 public:
  int minDeletionSize(std::vector<std::string>& strs) {
    int count{0};
    for (std::size_t j{0}; j < strs[0].size(); ++j) {
      for (std::size_t i{1}; i < strs.size(); ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          ++count;
          break;
        }
      }
    }
    return count;
  }
};
