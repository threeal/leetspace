#include <string>

extern "C" {
int minLength(char* s);
}

int solution_c(std::string s) {
  return minLength(s.data());
}
