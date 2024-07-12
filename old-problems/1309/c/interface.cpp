#include <string>

extern "C" {
char* freqAlphabets(char* s);
}

std::string solution_c(std::string s) {
  return freqAlphabets(s.data());
}
