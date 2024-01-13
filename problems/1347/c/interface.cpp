#include <string>

extern "C" {
int minSteps(char* s, char* t);
}

int solution_c(std::string s, std::string t) {
  return minSteps(s.data(), t.data());
}
