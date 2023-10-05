#include <interface.hpp>
#include <string>

extern "C" {
char* convert(char* s, int numRows);
}

template <>
std::string solution_c(const std::string& s, const int& numRows) {
  auto s_copy = s;
  return convert(s_copy.data(), numRows);
}
