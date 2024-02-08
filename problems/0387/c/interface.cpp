#include <string>

extern "C" {
int firstUniqChar(char* s);
}

int solution_c(std::string s) {
  return firstUniqChar(s.data());
}
