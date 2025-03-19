#include <math.h>

long long repairCars(int* ranks, int ranksSize, int cars) {
  long long low = 100, high = 1;
  for (int i = 0; i < ranksSize; ++i) {
    if (ranks[i] < low) low = ranks[i];
    if (ranks[i] > high) high = ranks[i];
  }

  high *= cars;
  high *= cars;

  while (low < high) {
    const long long mid = low + (high - low) / 2;

    long long count = 0;
    for (int i = 0; i < ranksSize; ++i) {
      count += sqrt(mid / ranks[i]);
    }

    if (count < cars) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}
