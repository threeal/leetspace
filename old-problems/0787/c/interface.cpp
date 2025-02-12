#include <vector>

extern "C" {
int findCheapestPrice(
    int n, int** flights, int flightsSize, int* flightsColSize,
    int src, int dst, int k);
}

int solution_c(
    int n, std::vector<std::vector<int>> flights, int src, int dst, int k) {
  std::vector<int*> flightsDatas(flights.size());
  std::vector<int> flightsSizes(flights.size());
  for (std::size_t i{0}; i < flights.size(); ++i) {
    flightsDatas[i] = flights[i].data();
    flightsSizes[i] = flights[i].size();
  }

  return findCheapestPrice(
      n, flightsDatas.data(), flightsDatas.size(), flightsSizes.data(),
      src, dst, k);
}
