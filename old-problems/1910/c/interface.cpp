#include <string>

extern "C" {
char* removeOccurrences(char* s, char* part);
}

std::string solution_c(std::string s, std::string part) {
  return removeOccurrences(s.data(), part.data());
}
