#include <string>

extern "C" {
int numSub(char* s);
}

int solution_c(std::string s) {
  return numSub(s.data());
}
