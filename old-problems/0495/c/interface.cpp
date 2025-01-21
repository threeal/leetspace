#include <vector>

extern "C" {
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration);
}

int solution_c(std::vector<int> timeSeries, int duration) {
  return findPoisonedDuration(timeSeries.data(), timeSeries.size(), duration);
}
