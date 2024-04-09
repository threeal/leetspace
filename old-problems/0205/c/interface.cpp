#include <string>

extern "C" {
bool isIsomorphic(char* s, char* t);
}

bool solution_c(std::string s, std::string t) {
  return isIsomorphic(s.data(), t.data());
}
