char* convert(char* s, int numRows) {
  if (numRows == 1) return s;

  int n = 0;
  while (s[n] != 0) {
    ++n;
  }

  char* res = malloc(sizeof(char) * (n + 1));

  int rn = (numRows - 1) * 2;

  int i = -1;

  for (int j = 0; j < n; j += rn) {
    res[++i] = s[j];
  }

  for (int r = 1; r < numRows - 1; ++r) {
    int rj = rn - (2 * r);
    for (int j = r; j < n; j += rn) {
      res[++i] = s[j];
      if (j + rj < n) {
        res[++i] = s[j + rj];
      }
    }
  }

  for (int j = numRows - 1; j < n; j += rn) {
    res[++i] = s[j];
  }

  res[++i] = 0;
  return res;
}
