#include <string>

class Solution {
 public:
  bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
    return firstWord == secondWord && secondWord == targetWord;
  }
};
