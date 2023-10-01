#include <string>

extern "C" {
char* reverseWords(char* s);
}

std::string solution_c(const std::string& s) {
  return reverseWords(const_cast<char*>(s.c_str()));
}
