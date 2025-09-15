#include <string>
#include <vector>

class Solution {
 public:
  int canBeTypedWords(std::string text, std::string brokenLetters) {
    std::vector<bool> isBrokenLetters(26, false);
    for (const char c : brokenLetters) {
      isBrokenLetters[c - 'a'] = true;
    }

    int count{0};
    bool isBroken{false};
    for (const char c : text) {
      if (c == ' ') {
        if (!isBroken) ++count;
        isBroken = false;
      } else if (!isBroken && isBrokenLetters[c - 'a']) {
        isBroken = true;
      }
    }

    return isBroken ? count : count + 1;
  }
};
