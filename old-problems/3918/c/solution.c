#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int sumOfPrimesInRange(int n) {
  int rn = 0;
  for (int nn = n; nn != 0; nn /= 10) {
    rn = rn * 10 + nn % 10;
  }

  const int min = rn < n ? rn : n;
  const int max = rn > n ? rn : n;

  int sum = 0;
  uint8_t* sieve = malloc((max / 8 + 1) * sizeof(uint8_t));
  memset(sieve, 0, (max / 8 + 1) * sizeof(uint8_t));

  for (int i = 2; i <= max; ++i) {
    if ((sieve[i / 8] & (1 << (i % 8))) != 0) continue;
    if (i >= min) sum += i;
    for (int j = i; j <= max; j += i) {
      sieve[j / 8] |= 1 << (j % 8);
    }
  }

  return sum;
}
