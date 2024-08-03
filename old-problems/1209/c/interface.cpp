#include <string>

extern "C" {
char* removeDuplicates(char* s, int k);
}

std::string solution_c(std::string s, int k) {
  return removeDuplicates(s.data(), k);
}
