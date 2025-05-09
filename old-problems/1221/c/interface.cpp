#include <string>

extern "C" {
int balancedStringSplit(char* s);
}

int solution_c(std::string s) {
  return balancedStringSplit(s.data());
}
