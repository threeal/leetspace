#include <string>

extern "C" {
char* trimTrailingVowels(char* s);
}

std::string solution_c(std::string s) {
  return trimTrailingVowels(s.data());
}
