#include <string>

extern "C" {
int takeCharacters(char* s, int k);
}

int solution_c(std::string s, int k) {
  return takeCharacters(s.data(), k);
}
