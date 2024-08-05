int minimumSwap(char* s1, char* s2) {
  int x1 = 0, y1 = 0;
  while (*s1 != 0) {
    if (*s1 != *s2) {
      if (*s1 == 'x') {
        ++x1;
      } else {
        ++y1;
      }
    }
    ++s1;
    ++s2;
  }

  return x1 % 2 == 0
      ? (y1 % 2 == 0 ? (x1 + y1) / 2 : -1)
      : (y1 % 2 == 0 ? -1 : (x1 + y1) / 2 + 1);
}
