#include <string>

class Solution {
 public:
  std::string answerString(std::string word, int numFriends) {
    word.resize(numFriends);
    return word;
  }
};
