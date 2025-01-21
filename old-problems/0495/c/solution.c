int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
  int totalDuration = duration;
  for (int i = 1; i < timeSeriesSize; ++i) {
    const int diff = timeSeries[i] - timeSeries[i - 1];
    totalDuration += duration < diff ? duration : diff;
  }
  return totalDuration;
}
