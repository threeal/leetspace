#include <stdlib.h>

static long long* gFact = NULL;
static long long* gInvFact = NULL;

static long long qpow(long long x, int n) {
  long long res = 1;
  while (n != 0) {
    if (n % 2 != 0) res = res * x % 1000000007;
    x = x * x % 1000000007;
    n /= 2;
  }
  return res;
}

static long long* calcFact(void) {
  long long* fact = malloc(100000 * sizeof(long long));
  fact[0] = 1;
  for (long long i = 1; i < 100000; ++i) {
    fact[i] = fact[i - 1] * i % 1000000007;
  }
  return fact;
}

static long long* calcInvFact(long long* fact) {
  long long* invFact = malloc(100000 * sizeof(long long));
  invFact[99999] = qpow(fact[99999], 1000000005);
  for (long long i = 99999; i > 0; --i) {
    invFact[i - 1] = invFact[i] * i % 1000000007;
  }
  return invFact;
}

int countGoodArrays(int n, int m, int k) {
  if (gFact == NULL) gFact = calcFact();
  if (gInvFact == NULL) gInvFact = calcInvFact(gFact);
  const long long comb = gFact[n - 1] * gInvFact[k] % 1000000007 *
      gInvFact[n - 1 - k] % 1000000007;
  return m * comb % 1000000007 * qpow(m - 1, n - 1 - k) % 1000000007;
}
