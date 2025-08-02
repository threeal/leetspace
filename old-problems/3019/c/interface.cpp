#include <string>

extern "C" {
int countKeyChanges(char* s);
}

int solution_c(std::string s) {
  return countKeyChanges(s.data());
}
