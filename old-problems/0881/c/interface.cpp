#include <vector>

extern "C" {
int numRescueBoats(int* people, int peopleSize, int limit);
}

int solution_c(std::vector<int> people, int limit) {
  return numRescueBoats(people.data(), people.size(), limit);
}
