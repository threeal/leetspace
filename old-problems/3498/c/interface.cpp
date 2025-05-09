#include <string>

extern "C" {
int reverseDegree(char* s);
}

int solution_c(std::string s) {
  return reverseDegree(s.data());
}
