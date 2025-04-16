#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* getPermutation(int n, int k) {
  char* permutation = malloc((n + 1) * sizeof(char));

  memset(permutation, '0', n * sizeof(char));
  permutation[n] = 0;

  int factorial = 1;
  for (int i = 2; i <= n; ++i) factorial *= i;

  uint16_t exists = 0;
  for (int i = 0; i < n; ++i) {
    factorial /= n - i;
    for (int j = 1; j <= 9; ++j) {
      if ((exists & (1 << j)) == 0) {
        if (k <= factorial) {
          exists |= 1 << j;
          permutation[i] += j;
          break;
        } else {
          k -= factorial;
        }
      }
    }
  }

  return permutation;
}
