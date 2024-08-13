#include <string>

extern "C" {
int minimumPushes(char* word);
}

int solution_c(std::string word) {
  return minimumPushes(word.data());
}
