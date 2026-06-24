int earliestFinishTime(
    int* landStartTime, int landStartTimeSize,
    int* landDuration, int landDurationSize,
    int* waterStartTime, int waterStartTimeSize,
    int* waterDuration, int waterDurationSize) {
  return landStartTime[landStartTimeSize - 1] +
      landDuration[landDurationSize - 1] +
      waterStartTime[waterStartTimeSize - 1] +
      waterDuration[waterDurationSize - 1];
}
