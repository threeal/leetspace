int mySqrt(int x) {
  if (x == 0) return 0;
  int low = 0, high = x;
  while (low < high) {
    const int mid = high - ((high - low) / 2);
    if (x / mid < mid) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  return low;
}
