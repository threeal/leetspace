#include <string>

extern "C" {
int longestCommonSubsequence(char* text1, char* text2);
}

int solution_c(std::string text1, std::string text2) {
  return longestCommonSubsequence(text1.data(), text2.data());
}
