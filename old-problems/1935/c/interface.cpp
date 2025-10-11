#include <string>

extern "C" {
int canBeTypedWords(char* text, char* brokenLetters);
}

int solution_c(std::string text, std::string brokenLetters) {
  return canBeTypedWords(text.data(), brokenLetters.data());
}
