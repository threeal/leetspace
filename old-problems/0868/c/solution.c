int binaryGap(int n) {
  unsigned int nn = n;
  nn >>= __builtin_ctz(nn) + 1;

  int maxGap = 0;
  while (nn != 0) {
    const int gap = __builtin_ctz(nn) + 1;
    if (gap >= maxGap) maxGap = gap;
    nn >>= gap;
  }

  return maxGap;
}
