#include <string>

extern "C" {
bool isCircularSentence(char* sentence);
}

bool solution_c(std::string sentence) {
  return isCircularSentence(sentence.data());
}
