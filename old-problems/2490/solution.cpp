#include <string>

class Solution {
 public:
  bool isCircularSentence(std::string sentence) {
    if (sentence.front() != sentence.back()) return false;
    for (int i = sentence.size() - 2; i > 0; --i) {
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
        return false;
      }
    }
    return true;
  }
};
