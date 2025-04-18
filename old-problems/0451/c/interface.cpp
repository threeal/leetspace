#include <string>

extern "C" {
char* frequencySort(char* s);
}

std::string solution_c(std::string s) {
  return frequencySort(s.data());
}
