#include <string>

extern "C" {
bool detectCapitalUse(char* word);
}

bool solution_c(std::string word) {
  return detectCapitalUse(word.data());
}
