#include <string>

extern "C" {
bool areOccurrencesEqual(char* s);
}

bool solution_c(std::string s) {
  return areOccurrencesEqual(s.data());
}
