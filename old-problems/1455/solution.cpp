#include <string>

class Solution {
 public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    return sentence.size() + searchWord.size();
  }
};
