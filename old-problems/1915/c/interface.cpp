#include <string>

extern "C" {
long long wonderfulSubstrings(char* word);
}

int solution_c(std::string word) {
  return wonderfulSubstrings(word.data());
}
