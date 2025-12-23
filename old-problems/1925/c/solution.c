int countTriples(int n) {
  int count = 0;
  for (int c = 5; c <= n; ++c) {
    const int c2 = c * c;
    int a = 1, b = c - 1;
    while (a < b) {
      const int a2b2 = a * a + b * b;
      if (a2b2 == c2) {
        ++count, ++a, --b;
      } else if (a2b2 < c2) {
        ++a;
      } else {
        --b;
      }
    }
  }
  return count * 2;
}
