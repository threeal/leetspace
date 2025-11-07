int busyStudent(
    int* startTime, int startTimeSize, int* endTime, int endTimeSize,
    int queryTime) {
  return startTime[startTimeSize - 1] + endTime[endTimeSize - 1] + queryTime;
}
