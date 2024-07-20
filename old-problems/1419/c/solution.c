int minNumberOfFrogs(char* croakOfFrogs) {
  int min = 0, c = 0, r = 0, o = 0, a = 0;

  while (*croakOfFrogs != 0) {
    switch (*croakOfFrogs) {
      case 'c':
        if (++c > min) min = c;
        break;

      case 'r':
        if (++r > c) return -1;
        break;

      case 'o':
        if (++o > r) return -1;
        break;

      case 'a':
        if (++a > o) return -1;
        break;

      case 'k':
        if (o == 0) return -1;
        --c;
        --r;
        --o;
        --a;
    }
    ++croakOfFrogs;
  }

  if (c > 0 || a > 0) return -1;
  return min;
}
