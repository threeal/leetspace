#include <string>

extern "C" {
bool isPalindrome(char* s);
}

bool solution_c(std::string s) {
  return isPalindrome(s.data());
}
