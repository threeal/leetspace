#include <string>

extern "C" {
bool isValid(char* word);
}

long long solution_c(std::string word) {
  return isValid(word.data());
}
