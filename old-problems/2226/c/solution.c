int maximumCandies(int* candies, int candiesSize, long long k) {
  int low = 0, high = 0;
  for (int i = 0; i < candiesSize; ++i) {
    if (candies[i] > high) high = candies[i];
  }

  while (low < high) {
    const int mid = high - (high - low) / 2;

    long long piles = 0;
    if (mid > 0) {
      for (int i = 0; i < candiesSize; ++i) {
        piles += candies[i] / mid;
      }
    }

    if (piles >= k) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  return low;
}
