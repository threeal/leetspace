int climbStairs(int n) {
  if (n <= 2) return n;

  int a = 1;
  int b = 2;

  for (int i = 3; i <= n; ++i) {
    const int val = a + b;
    a = b;
    b = val;
  }

  return b;
}
