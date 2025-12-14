int totalFruit(int* fruits, int fruitsSize) {
  int b = 1;
  while (b < fruitsSize && fruits[b] == fruits[0]) ++b;
  if (b == fruitsSize) return b;

  int a = b - 1, max = b + 1;
  for (int l = 0, r = b + 1; r < fruitsSize; ++r) {
    if (fruits[r] == fruits[a]) {
      a = b;
      b = r;
      if (r + 1 - l > max) max = r + 1 - l;
    } else if (fruits[r] == fruits[b]) {
      b = r;
      if (r + 1 - l > max) max = r + 1 - l;
    } else {
      l = a + 1;
      a = b;
      b = r;
    }
  }

  return max;
}
