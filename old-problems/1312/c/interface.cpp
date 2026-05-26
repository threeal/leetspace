#include <string>

extern "C" {
int minInsertions(char* s);
}

int solution_c(std::string s) {
  return minInsertions(s.data());
}
