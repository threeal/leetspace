#include <string>

extern "C" {
int scoreOfString(char* s);
}

int solution_c(std::string s) {
  return scoreOfString(s.data());
}
