double myPow(double x, int n) {
  unsigned int un;
  if (n < 0) {
    x = 1.0 / x;
    un = n == -2147483648 ? 2147483648u : -n;
  } else {
    un = n;
  }

  double ans = 1.0;
  while (un != 0) {
    if ((un & 1) != 0) ans *= x;
    x *= x;
    un >>= 1;
  }

  return ans;
}
