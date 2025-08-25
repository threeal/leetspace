#include <string>

extern "C" {
int minimumDeletions(char* word, int k);
}

int solution_c(std::string word, int k) {
  return minimumDeletions(word.data(), k);
}
