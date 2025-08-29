#include <string>

extern "C" {
int minTimeToType(char* word);
}

int solution_c(std::string word) {
  return minTimeToType(word.data());
}
