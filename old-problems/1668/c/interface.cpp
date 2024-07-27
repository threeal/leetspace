#include <string>

extern "C" {
int maxRepeating(char* sequence, char* word);
}

int solution_c(std::string sequence, std::string word) {
  return maxRepeating(sequence.data(), word.data());
}
