#include <vector>

extern "C" {
int maxFreeTime(
    int eventTime, int k, int* startTime, int startTimeSize,
    int* endTime, int endTimeSize);
}

int solution_c(
    int eventTime, int k, std::vector<int> startTime,
    std::vector<int> endTime) {
  return maxFreeTime(
      eventTime, k, startTime.data(), startTime.size(),
      endTime.data(), endTime.size());
}
