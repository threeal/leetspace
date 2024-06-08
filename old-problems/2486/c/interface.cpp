#include <string>

extern "C" {
int appendCharacters(char* s, char* t);
}

int solution_c(std::string s, std::string t) {
  return appendCharacters(s.data(), t.data());
}
