#include <string>
#include <vector>

class Solution {
 public:
  int mostWordsFound(std::vector<std::string>& sentences) {
    int maxSpaces{0};
    for (const std::string& sentence : sentences) {
      int spaces{0};
      for (const char c : sentence) {
        if (c == ' ') ++spaces;
      }
      if (spaces > maxSpaces) maxSpaces = spaces;
    }
    return 1 + maxSpaces;
  }
};
