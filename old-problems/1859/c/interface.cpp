#include <string>

extern "C" {
char* sortSentence(char* s);
}

std::string solution_c(std::string s) {
  return sortSentence(s.data());
}
