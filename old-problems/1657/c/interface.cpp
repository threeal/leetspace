#include <string>

extern "C" {
bool closeStrings(char* word1, char* word2);
}

bool solution_c(std::string word1, std::string word2) {
  return closeStrings(word1.data(), word2.data());
}
