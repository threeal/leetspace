#include <vector>

extern "C" {
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination);
}

int solution_c(std::vector<int> distance, int start, int destination) {
  return distanceBetweenBusStops(distance.data(), distance.size(), start, destination);
}
