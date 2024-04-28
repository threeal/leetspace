int tribonacci(int n) {
  switch (n) {
    case 0:
      return 0;
    case 1:
      return 1;
    case 2:
      return 1;
  }

  int t[3] = {0, 1, 1};
  while (--n >= 2) {
    const int val = t[0] + t[1] + t[2];
    t[0] = t[1];
    t[1] = t[2];
    t[2] = val;
  }

  return t[2];
}
