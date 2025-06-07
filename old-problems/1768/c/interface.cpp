#include <string>

extern "C" {
char* mergeAlternately(char* word1, char* word2);
}

std::string solution_c(std::string word1, std::string word2) {
  return mergeAlternately(word1.data(), word2.data());
}
