#include <string>

extern "C" {
int minChanges(char* s);
}

int solution_c(std::string s) {
  return minChanges(s.data());
}
