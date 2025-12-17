#include <string>

extern "C" {
int countVowelSubstrings(char* word);
}

int solution_c(std::string word) {
  return countVowelSubstrings(word.data());
}
