static long long powi(long long x, long long n);

int countGoodNumbers(long long n) {
  return (powi(5, n / 2 + n % 2) * powi(4, n / 2)) % 1000000007;
}

static long long powi(long long x, long long n) {
  long long res = 1;
  while (n != 0) {
    if (n % 2) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    n /= 2;
  }
  return res;
}
