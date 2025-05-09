#include <string>

extern "C" {
char* pushDominoes(char* dominoes);
}

std::string solution_c(std::string dominoes) {
  return pushDominoes(dominoes.data());
}
