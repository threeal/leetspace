#include <string>

extern "C" {
int removePalindromeSub(char* s);
}

int solution_c(std::string s) {
  return removePalindromeSub(s.data());
}
