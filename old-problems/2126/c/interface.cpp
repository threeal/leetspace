#include <vector>

extern "C" {
bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize);
}

bool solution_c(int mass, std::vector<int> asteroids) {
  return asteroidsDestroyed(mass, asteroids.data(), asteroids.size());
}
