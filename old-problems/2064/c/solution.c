int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
  int low = 1;
  int high = 100000;

  while (low < high) {
    const int mid = low + (high - low) / 2;

    int count = 0;
    for (int i = 0; i < quantitiesSize; ++i) {
      count += quantities[i] / mid;
      if (quantities[i] % mid != 0) ++count;
    }

    if (count <= n) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}
