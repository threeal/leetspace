long long minEnd(int n, int x) {
  long long res = 0, mask = 1, nn = n - 1, xx = x;
  while (mask <= nn || mask <= xx) {
    if ((xx & mask) != 0) {
      nn = nn << 1;
      res |= mask;
    } else if ((nn & mask) != 0) {
      res |= mask;
    }
    mask = mask << 1;
  }
  return res;
}
