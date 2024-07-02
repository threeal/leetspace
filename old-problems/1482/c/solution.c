int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
  if (bloomDaySize / m < k) return -1;

  int high = bloomDay[0];
  int low = bloomDay[0];
  for (int i = bloomDaySize - 1; i > 0; --i) {
    if (bloomDay[i] > high) {
      high = bloomDay[i];
    } else if (bloomDay[i] < low) {
      low = bloomDay[i];
    }
  }
  if (bloomDaySize % m == 0 && bloomDaySize / m == k) return high;

  while (low < high) {
    const int mid = (low + high) / 2;

    int bouquets = 0;
    for (int i = bloomDaySize - 1; i >= 0; --i) {
      if (bloomDay[i] > mid) continue;
      if (i < k - 1) break;

      int j = k;
      while (--j > 0) {
        if (bloomDay[--i] > mid) break;
      }

      if (j <= 0) ++bouquets;
    }

    if (bouquets < m) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}
