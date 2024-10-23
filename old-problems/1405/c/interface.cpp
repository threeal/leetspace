#include <string>

extern "C" {
char* longestDiverseString(int a, int b, int c);
}

std::string solution_c(int a, int b, int c) {
  return longestDiverseString(a, b, c);
}
