int countGoodRectangles(
    int** rectangles, int rectanglesSize, int* rectanglesColSize) {
  (void)rectanglesColSize;
  int count = 0, maxK = 0;
  for (int i = 0; i < rectanglesSize; ++i) {
    const int k = rectangles[i][0] <= rectangles[i][1]
        ? rectangles[i][0]
        : rectangles[i][1];

    if (k < maxK) continue;
    if (k == maxK) {
      ++count;
    } else {
      maxK = k;
      count = 1;
    }
  }
  return count;
}
