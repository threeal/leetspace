#include <string>

extern "C" {
int countPoints(char* rings);
}

int solution_c(std::string rings) {
  return countPoints(rings.data());
}
