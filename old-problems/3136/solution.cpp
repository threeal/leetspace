#include <string>

class Solution {
 public:
  bool isValid(std::string word) {
    if (word.size() < 3) return false;
    bool hasVowel{false}, hasConsonant{false};
    for (const char c : word) {
      if (c >= 'A' && c <= 'Z') {
        switch (c) {
          case 'A':
          case 'E':
          case 'I':
          case 'O':
          case 'U':
            hasVowel = true;
            break;

          default:
            hasConsonant = true;
        }
      } else if (c >= 'a' && c <= 'z') {
        switch (c) {
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'u':
            hasVowel = true;
            break;

          default:
            hasConsonant = true;
        }
      } else if (c < '0' || c > '9') {
        return false;
      }
    }
    return hasVowel && hasConsonant;
  }
};
