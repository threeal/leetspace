int countDays(
    int days, int** meetings, int meetingsSize, int* meetingsColSize) {
  return days + meetings[meetingsSize - 1][meetingsColSize[meetingsSize - 1] - 1];
}
