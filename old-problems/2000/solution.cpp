#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reversePrefix(std::string word, char ch) {
    for (auto it{word.begin()}; it != word.end(); ++it) {
      if (*it == ch) {
        std::reverse(word.begin(), it + 1);
        break;
      }
    }
    return word;
  }
};
