#include <string>

extern "C" {
int isPrefixOfWord(char* sentence, char* searchWord);
}

int solution_c(std::string sentence, std::string searchWord) {
  return isPrefixOfWord(sentence.data(), searchWord.data());
}
