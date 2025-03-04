#include <string>

extern "C" {
int percentageLetter(char* s, char letter);
}

int solution_c(std::string s, char letter) {
  return percentageLetter(s.data(), letter);
}
