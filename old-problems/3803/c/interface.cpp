#include <string>

extern "C" {
int residuePrefixes(char* s);
}

int solution_c(std::string s) {
  return residuePrefixes(s.data());
}
