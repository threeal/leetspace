double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
  (void)squaresColSize;

  double lowY = squares[0][1];
  double highY = squares[0][1] + squares[0][2];
  for (int i = 1; i < squaresSize; ++i) {
    double low = squares[i][1];
    if (low < lowY) lowY = low;

    double high = squares[i][1] + squares[i][2];
    if (high > highY) highY = high;
  }

  while (highY - lowY >= 0.00001) {
    const double midY = lowY + (highY - lowY) / 2;

    double lowSum = 0, highSum = 0;
    for (int i = 0; i < squaresSize; ++i) {
      const double y = squares[i][1], l = squares[i][2];
      if (y >= midY) {
        highSum += l * l;
      } else if (y + l <= midY) {
        lowSum += l * l;
      } else {
        lowSum += (midY - y) * l;
        highSum += (y + l - midY) * l;
      }
    }

    if (lowSum >= highSum) {
      highY = midY;
    } else {
      lowY = midY;
    }
  }

  return lowY;
}
