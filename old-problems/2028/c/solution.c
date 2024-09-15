#include <stdlib.h>

int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
  int observedTotal = 0;
  for (int i = rollsSize - 1; i >= 0; --i) {
    observedTotal += rolls[i];
  }

  const int missingTotal = mean * (rollsSize + n) - observedTotal;

  if (missingTotal < n || missingTotal > n * 6) {
    *returnSize = 0;
    return NULL;
  }

  *returnSize = n;
  int* out = malloc(n * sizeof(int));
  for (int i = missingTotal % n - 1; i >= 0; --i) out[i] = missingTotal / n + 1;
  for (int i = missingTotal % n; i < n; ++i) out[i] = missingTotal / n;

  return out;
}
