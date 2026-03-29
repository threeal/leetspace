#include <string>

extern "C" {
char* getEncryptedString(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return getEncryptedString(s.data(), k);
}
