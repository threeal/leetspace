long long maxRunTime(int n, int* batteries, int batteriesSize) {
  long long low = 0, high = 0;
  for (int i = 0; i < batteriesSize; ++i) high += batteries[i];

  while (low < high) {
    const long long mid = high - (high - low) / 2;
    long long extra = 0;

    for (int i = 0; i < batteriesSize; ++i) {
      extra += batteries[i] < mid ? batteries[i] : mid;
    }

    if (extra >= n * mid) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  return low;
}
