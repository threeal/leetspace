#include <string>

extern "C" {
char* reversePrefix(char* word, char ch);
}

std::string solution_c(std::string word, char ch) {
  return reversePrefix(word.data(), ch);
}
