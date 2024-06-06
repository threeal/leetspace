#include <string>

extern "C" {
char* addBinary(char* a, char* b);
}

std::string solution_c(std::string a, std::string b) {
  return addBinary(a.data(), b.data());
}
