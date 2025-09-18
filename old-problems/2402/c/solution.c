int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
  return n + meetings[meetingsSize - 1][meetingsColSize[meetingsSize - 1] - 1];
}
