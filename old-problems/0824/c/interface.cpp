#include <string>

extern "C" {
char* toGoatLatin(char* sentence);
}

std::string solution_c(std::string sentence) {
  return toGoatLatin(sentence.data());
}
