#include <string>

extern "C" {
int romanToInt(char* s);
}

int solution_c(std::string s) {
  return romanToInt(s.data());
}
