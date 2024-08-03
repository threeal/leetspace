#include <string>

extern "C" {
char* reverseVowels(char* s);
}

std::string solution_c(std::string s) {
  return reverseVowels(s.data());
}
