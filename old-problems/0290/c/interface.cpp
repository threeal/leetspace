#include <string>

extern "C" {
bool wordPattern(char* pattern, char* s);
}

bool solution_c(std::string pattern, std::string s) {
  return wordPattern(pattern.data(), s.data());
}
