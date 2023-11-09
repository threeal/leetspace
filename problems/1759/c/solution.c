// The count of homogeneous substrings is equal to the sum of the series of the maximum length of homogeneous substrings.
//
// For example, if the string is "aabbb", then:
//
// "a" appears 2 times.
// "aa" appears 1 time.
// "b" appears 3 times.
// "bb" appears 2 times.
// "bbb" appears 1 time.
//
// So, the total is:
//
// (1 + 2) + (1 + 2 + 3) = 9
//
// Or, roughly speaking, it equals the sum of the series from 1 to 2 (from "aa") and the series from 1 to 3 (from "bbb").

const long long mod = 1000000007;

// Calculate the sum of a series from 1 to n.
long long calculateSeries(long long n) {
  if (n <= 1) return n;
  return ((n + 1) * n) / 2;
}

int countHomogenous(char *s) {
  long long total = 0;

  // Find the maximum length of each homogeneous substring and sum the series.
  char prev = 0;
  long long length = 0;
  while (*s != 0) {
    if (*s == prev) {
      ++length;
    } else {
      total = (total + calculateSeries(length)) % mod;
      prev = *s;
      length = 1;
    }
    ++s;
  }

  return (total + calculateSeries(length)) % mod;
}
