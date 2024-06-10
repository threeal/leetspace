#include <string>

extern "C" {
int numSteps(char* s);
}

int solution_c(std::string s) {
  return numSteps(s.data());
}
