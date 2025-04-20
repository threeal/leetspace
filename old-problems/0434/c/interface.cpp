#include <string>

extern "C" {
int countSegments(char* s);
}

int solution_c(std::string s) {
  return countSegments(s.data());
}
