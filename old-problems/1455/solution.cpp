#include <string>

class Solution {
 public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    int i{1};
    char* ca{sentence.data()};

    while (true) {
      char* cb{searchWord.data()};
      while (*cb != 0 && *ca == *cb) {
        ++ca;
        ++cb;
      }

      if (*cb == 0) return i;
      while (*ca >= 'a') ++ca;

      if (*ca == 0) break;

      ++i;
      ++ca;
    }

    return -1;
  }
};
