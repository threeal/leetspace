int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
  return timeSeries[timeSeriesSize - 1] * duration;
}
