#include <vector>

extern "C" {
int largestAltitude(int* gain, int gainSize);
}

int solution_c(std::vector<int> gain) {
  return largestAltitude(gain.data(), gain.size());
}
