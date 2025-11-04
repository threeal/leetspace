int maxFreeTime(
    int eventTime, int* startTime, int startTimeSize,
    int* endTime, int endTimeSize) {
  return eventTime + startTime[startTimeSize - 1] + endTime[endTimeSize - 1];
}
