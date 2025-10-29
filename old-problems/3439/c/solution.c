int maxFreeTime(
    int eventTime, int k, int* startTime, int startTimeSize,
    int* endTime, int endTimeSize) {
  return eventTime + k + startTime[startTimeSize - 1] +
      endTime[endTimeSize - 1];
}
