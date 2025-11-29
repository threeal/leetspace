#include <string>

extern "C" {
int minFlips(char* target);
}

int solution_c(std::string target) {
  return minFlips(target.data());
}
