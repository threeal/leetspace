#include <string>

extern "C" {
bool isItPossible(char* word1, char* word2);
}

bool solution_c(std::string word1, std::string word2) {
  return isItPossible(word1.data(), word2.data());
}
