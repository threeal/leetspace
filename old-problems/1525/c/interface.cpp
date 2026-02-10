#include <string>

extern "C" {
int numSplits(char* s);
}

int solution_c(std::string s) {
  return numSplits(s.data());
}
