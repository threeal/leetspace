long long getDescentPeriods(int* prices, int pricesSize) {
  long long sum = 1;
  for (int l = 0, r = 1; r < pricesSize; ++r) {
    if (prices[r - 1] - prices[r] != 1) l = r;
    sum += r - l + 1;
  }
  return sum;
}
