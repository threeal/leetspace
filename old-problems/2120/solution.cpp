#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> executeInstructions(
      int n, std::vector<int>& startPos, std::string s) {
    std::vector<int> output(s.size());
    for (std::size_t i{0}; i < s.size(); ++i) {
      int y{startPos[0]}, x{startPos[1]};
      std::size_t j{i};
      while (j < s.size()) {
        if (s[j] == 'L') {
          if (--x < 0) break;
        } else if (s[j] == 'R') {
          if (++x >= n) break;
        } else if (s[j] == 'U') {
          if (--y < 0) break;
        } else {
          if (++y >= n) break;
        }
        ++j;
      }
      output[i] = j - i;
    }
    return output;
  }
};
