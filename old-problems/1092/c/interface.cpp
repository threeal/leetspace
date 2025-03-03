#include <string>

extern "C" {
char* shortestCommonSupersequence(char* str1, char* str2);
}

std::string solution_c(std::string str1, std::string str2) {
  return shortestCommonSupersequence(str1.data(), str2.data());
}
