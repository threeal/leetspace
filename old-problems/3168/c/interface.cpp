#include <string>

extern "C" {
int minimumChairs(char* s);
}

int solution_c(std::string s) {
  return minimumChairs(s.data());
}
