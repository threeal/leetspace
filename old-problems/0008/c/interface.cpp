#include <string>

extern "C" {
int myAtoi(char* s);
}

int solution_c(std::string s) {
  return myAtoi(s.data());
}
