#include <vector>

extern "C" {
int maxFreeTime(
    int eventTime, int* startTime, int startTimeSize,
    int* endTime, int endTimeSize);
}

int solution_c(
    int eventTime, std::vector<int> startTime, std::vector<int> endTime) {
  return maxFreeTime(
      eventTime, startTime.data(), startTime.size(),
      endTime.data(), endTime.size());
}
