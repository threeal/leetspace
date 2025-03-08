long long coloredCells(int n) {
  const long long nn = n;
  return 1 + (nn - 1) * (4 + 4 * (nn - 1)) / 2;
}
