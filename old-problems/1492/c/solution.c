int kthFactor(int n, int k) {
  const int n2 = n / 2;
  for (int i = 1; i <= n2; ++i) {
    if (n % i == 0) {
      if (--k == 0) {
        return i;
      }
    }
  }
  return k == 1 ? n : -1;
}
