#include <string>

extern "C" {
char* smallestEquivalentString(char* s1, char* s2, char* baseStr);
}

std::string solution_c(std::string s1, std::string s2, std::string baseStr) {
  return smallestEquivalentString(s1.data(), s2.data(), baseStr.data());
}
