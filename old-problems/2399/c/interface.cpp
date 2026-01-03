#include <string>
#include <vector>

extern "C" {
bool checkDistances(char* s, int* distance, int distanceSize);
}

bool solution_c(std::string s, std::vector<int> distance) {
  return checkDistances(s.data(), distance.data(), distance.size());
}
