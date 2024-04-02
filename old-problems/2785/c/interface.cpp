#include <cstring>
#include <string>

extern "C" {
char* sortVowels(char* s);
}

std::string solution_c(std::string s) {
  const auto res = sortVowels(s.data());
  memcpy(s.data(), res, s.size() + 1);
  return s;
}
