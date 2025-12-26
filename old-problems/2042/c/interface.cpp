#include <string>

extern "C" {
bool areNumbersAscending(char* s);
}

bool solution_c(std::string s) {
  return areNumbersAscending(s.data());
}
