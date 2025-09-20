#include <string>

extern "C" {
int minimizedStringLength(char* s);
}

int solution_c(std::string s) {
  return minimizedStringLength(s.data());
}
