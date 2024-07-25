#include <string>

extern "C" {
char* gcdOfStrings(char* str1, char* str2);
}

std::string solution_c(std::string str1, std::string str2) {
  return gcdOfStrings(str1.data(), str2.data());
}
