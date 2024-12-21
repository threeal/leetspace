#include <string>

extern "C" {
int maximumLength(char* s);
}

int solution_c(std::string s) {
  return maximumLength(s.data());
}
