#include <string>

extern "C" {
bool checkIfCanBreak(char* s1, char* s2);
}

bool solution_c(std::string s1, std::string s2) {
  return checkIfCanBreak(s1.data(), s2.data());
}
