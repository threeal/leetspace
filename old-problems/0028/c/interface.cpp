#include <string>

extern "C" {
int strStr(char* haystack, char* needle);
}

int solution_c(std::string haystack, std::string needle) {
  return strStr(haystack.data(), needle.data());
}
