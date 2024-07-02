#include <string>

extern "C" {
bool equalFrequency(char* word);
}

bool solution_c(std::string word) {
  return equalFrequency(word.data());
}
