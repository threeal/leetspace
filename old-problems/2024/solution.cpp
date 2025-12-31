#include <string>

class Solution {
 public:
  int maxConsecutiveAnswers(std::string answerKey, int k) {
    return answerKey.size() + k;
  }
};
