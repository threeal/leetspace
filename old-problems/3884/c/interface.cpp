#include <string>

extern "C" {
int firstMatchingIndex(char* s);
}

int solution_c(std::string s) {
  return firstMatchingIndex(s.data());
}
