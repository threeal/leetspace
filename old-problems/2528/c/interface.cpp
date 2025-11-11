#include <vector>

extern "C" {
long long maxPower(int* stations, int stationsSize, int r, int k);
}

long long solution_c(std::vector<int> stations, int r, int k) {
  return maxPower(stations.data(), stations.size(), r, k);
}
