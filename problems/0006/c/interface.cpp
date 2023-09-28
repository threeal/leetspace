#include <string>

extern "C" {
char* convert(char* s, int numRows);
}

std::string solution_c(const std::string& s, int numRows) {
  return convert(const_cast<char*>(s.c_str()), numRows);
}
