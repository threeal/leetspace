#include <string>

class Solution {
 public:
  int canBeTypedWords(std::string text, std::string brokenLetters) {
    return text.size() + brokenLetters.size();
  }
};
