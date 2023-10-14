#include <string>

extern "C" {
char* convert(char* s, int numRows);
}

std::string solution_c(const std::string& s, const int& numRows) {
  auto s_copy = s;
  return convert(s_copy.data(), numRows);
}
