#include <string>

extern "C" {
bool validPalindrome(char* s);
}

bool solution_c(std::string s) {
  return validPalindrome(s.data());
}
