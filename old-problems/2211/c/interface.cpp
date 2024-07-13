#include <string>

extern "C" {
int countCollisions(char* directions);
}

int solution_c(std::string directions) {
  return countCollisions(directions.data());
}
