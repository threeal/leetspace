#include <string>

extern "C" {
int minFlips(char* s);
}

int solution_c(std::string s) {
  return minFlips(s.data());
}
