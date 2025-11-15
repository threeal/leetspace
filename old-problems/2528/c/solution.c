#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

long long maxPower(int* stations, int stationsSize, int r, int k) {
  long long startSum = 0;
  for (int i = 0; i < r; ++i) startSum += stations[i];

  long long sum = startSum;
  long long low = INT_MAX;
  long long high = INT_MIN;
  for (int i = 0; i < stationsSize; ++i) {
    if (i + r < stationsSize) sum += stations[i + r];
    if (sum < low) low = sum;
    if (sum > high) high = sum;
    if (i >= r) sum -= stations[i - r];
  }
  high += k;

  int* powers = malloc(stationsSize * sizeof(int));
  while (low < high) {
    const long long mid = high - (high - low) / 2;

    long long kk = k;
    long long sum = startSum;
    for (int i = 0; i < stationsSize; ++i) powers[i] = 0;

    bool valid = true;
    for (int i = 0; i < stationsSize; ++i) {
      if (i + r < stationsSize) sum += stations[i + r];

      if (sum < mid) {
        if (mid - sum <= kk) {
          const int idx = i + r <= stationsSize - 1
              ? i + r
              : stationsSize - 1;

          powers[idx] = mid - sum;
          kk -= mid - sum;
          sum = mid;
        } else {
          valid = false;
          break;
        }
      }

      if (i >= r) sum -= stations[i - r] + powers[i - r];
    }

    if (valid) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  free(powers);
  return low;
}
