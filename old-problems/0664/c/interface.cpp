#include <string>

extern "C" {
int strangePrinter(char* s);
}

int solution_c(std::string s) {
  return strangePrinter(s.data());
}
