#include <string>

extern "C" {
int minAddToMakeValid(char* s);
}

int solution_c(std::string s) {
  return minAddToMakeValid(s.data());
}
