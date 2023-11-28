#include <string>

extern "C" {
int numberOfWays(char* corridor);
}

int solution_c(std::string corridor) {
  return numberOfWays(corridor.data());
}
