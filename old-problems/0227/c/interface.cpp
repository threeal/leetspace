#include <string>

extern "C" {
int calculate(char* s);
}

int solution_c(std::string s) {
  return calculate(s.data());
}
