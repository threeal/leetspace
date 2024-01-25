#include <string>

extern "C" {
bool isMatch(char* s, char* p);
}

bool solution_c(std::string s, std::string p) {
  return isMatch(s.data(), p.data());
}
