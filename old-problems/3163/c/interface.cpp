#include <string>

extern "C" {
char* compressedString(char* word);
}

std::string solution_c(std::string word) {
  return compressedString(word.data());
}
