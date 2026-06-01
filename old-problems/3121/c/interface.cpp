#include <string>

extern "C" {
int numberOfSpecialChars(char* word);
}

int solution_c(std::string word) {
  return numberOfSpecialChars(word.data());
}
