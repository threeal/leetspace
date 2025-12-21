#include <string>

extern "C" {
int countSubstrings(char* s, char* t);
}

int solution_c(std::string s, std::string t) {
  return countSubstrings(s.data(), t.data());
}
