#include <string>

extern "C" {
int countHomogenous(char *s);
}

int solution_c(std::string s) {
  return countHomogenous(s.data());
}
