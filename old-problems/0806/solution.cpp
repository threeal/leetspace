#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> numberOfLines(std::vector<int>& widths, std::string s) {
    int lines{1}, width{0};
    for (char c : s) {
      if (width + widths[c - 'a'] > 100) {
        ++lines;
        width = 0;
      }
      width += widths[c - 'a'];
    }
    return {lines, width};
  }
};
