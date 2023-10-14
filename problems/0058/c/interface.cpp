#include <interface.hpp>
#include <string>

extern "C" {
int lengthOfLastWord(char* s);
}

template <>
int solution_c(const std::string& s) {
  auto s_copy = s;
  return lengthOfLastWord(s_copy.data());
}
