#include <string>

extern "C" {
int findRotateSteps(char* ring, char* key);
}

int solution_c(std::string ring, std::string key) {
  return findRotateSteps(ring.data(), key.data());
}
