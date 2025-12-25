int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
  return events[eventsSize - 1][eventsColSize[eventsSize - 1] - 1];
}
