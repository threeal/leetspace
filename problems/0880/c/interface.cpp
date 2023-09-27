#include <iostream>

extern "C" {
char* decodeAtIndex(char* s, int k);
}

std::string solution_c(const std::string& s, int k) {
  return decodeAtIndex(const_cast<char*>(s.c_str()), k);
}
