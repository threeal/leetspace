#include <string>

extern "C" {
char* truncateSentence(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return truncateSentence(s.data(), k);
}
