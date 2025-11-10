#include <vector>

extern "C" {
int busyStudent(
    int* startTime, int startTimeSize, int* endTime, int endTimeSize,
    int queryTime);
}

int solution_c(
    std::vector<int> startTime, std::vector<int> endTime, int queryTime) {
  return busyStudent(
      startTime.data(), startTime.size(), endTime.data(), endTime.size(),
      queryTime);
}
