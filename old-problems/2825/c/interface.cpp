#include <string>

extern "C" {
bool canMakeSubsequence(char* str1, char* str2);
}

bool solution_c(std::string str1, std::string str2) {
  return canMakeSubsequence(str1.data(), str2.data());
}
