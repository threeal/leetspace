#include <string>

extern "C" {
char* convert(char* s, int numRows);
}

std::string solution_c(std::string s, int numRows) {
  return convert(s.data(), numRows);
}
