#include <string>

extern "C" {
int numDecodings(char* s);
}

int solution_c(std::string s) {
  return numDecodings(s.data());
}
