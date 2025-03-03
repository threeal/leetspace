#include <string>

extern "C" {
int numDistinct(char* s, char* t);
}

int solution_c(std::string s, std::string t) {
  return numDistinct(s.data(), t.data());
}
