#include <string>

extern "C" {
int maxConsecutiveAnswers(char* answerKey, int k);
}

int solution_c(std::string answerKey, int k) {
  return maxConsecutiveAnswers(answerKey.data(), k);
}
