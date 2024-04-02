#include <string>

extern "C" {
int maxScore(char* s);
}

int solution_c(std::string s) {
  return maxScore(s.data());
}
