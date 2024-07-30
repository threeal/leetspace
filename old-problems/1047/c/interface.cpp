#include <string>

extern "C" {
char* removeDuplicates(char* s);
}

std::string solution_c(std::string s) {
  return removeDuplicates(s.data());
}
