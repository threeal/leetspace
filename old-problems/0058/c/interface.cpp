#include <string>

extern "C" {
int lengthOfLastWord(char* s);
}

int solution_c(std::string s) {
  return lengthOfLastWord(s.data());
}
