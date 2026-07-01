#include <vector>

extern "C" {
int earliestFinishTime(
    int* landStartTime, int landStartTimeSize,
    int* landDuration, int landDurationSize,
    int* waterStartTime, int waterStartTimeSize,
    int* waterDuration, int waterDurationSize);
}

int solution_c(
    std::vector<int> landStartTime, std::vector<int> landDuration,
    std::vector<int> waterStartTime, std::vector<int> waterDuration) {
  return earliestFinishTime(
      landStartTime.data(), landStartTime.size(),
      landDuration.data(), landDuration.size(),
      waterStartTime.data(), waterStartTime.size(),
      waterDuration.data(), waterDuration.size());
}
