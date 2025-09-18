#include <string>
#include <vector>

extern "C" {
char* repeatLimitedString(char* s, int repeatLimit);
}

std::string solution_c(std::string s, int repeatLimit) {
  return repeatLimitedString(s.data(), repeatLimit);
}
