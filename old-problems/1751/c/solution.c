int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
  return events[eventsSize - 1][eventsColSize[eventsSize - 1] - 1] + k;
}
