#include <string>

extern "C" {
bool isSumEqual(char* firstWord, char* secondWord, char* targetWord);
}

bool solution_c(
    std::string firstWord, std::string secondWord, std::string targetWord) {
  return isSumEqual(firstWord.data(), secondWord.data(), targetWord.data());
}
