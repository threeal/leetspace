#include <string>

extern "C" {
int maxDifference(char* s);
}

int solution_c(std::string s) {
  return maxDifference(s.data());
}
