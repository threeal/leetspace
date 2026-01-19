#include <vector>

extern "C" {
int shortestSequence(int* rolls, int rollsSize, int k);
}

int solution_c(std::vector<int> rolls, int k) {
  return shortestSequence(rolls.data(), rolls.size(), k);
}
