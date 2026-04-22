int minOperations(char* s, int k) {
  int n = 0, zeros = 0;
  while (s[n] != 0) {
    if (s[n] == '0') ++zeros;
    ++n;
  }

  if (zeros == 0) return 0;
  if (n == k) return zeros == k ? 1 : -1;

  const int ones = n - zeros;
  const int nk = n - k;

  const int even0 = (zeros + k - 1) / k;
  const int even1 = (zeros + nk - 1) / nk;
  int even = even0 > even1 ? even0 : even1;
  if (even % 2 == 1) ++even;

  if (k % 2 == zeros % 2) {
    const int odd0 = (zeros + k - 1) / k;
    const int odd1 = (ones + nk - 1) / nk;
    int odd = odd0 > odd1 ? odd0 : odd1;
    if (odd % 2 == 0) ++odd;
    return zeros % 2 == 0 ? (even < odd ? even : odd) : odd;
  }

  return zeros % 2 == 0 ? even : -1;
}
