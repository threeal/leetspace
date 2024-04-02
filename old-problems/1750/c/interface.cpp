#include <string>

extern "C" {
int minimumLength(char* s);
}

int solution_c(std::string s) {
  return minimumLength(s.data());
}
