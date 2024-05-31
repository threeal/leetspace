int hIndex(int* citations, int citationsSize) {
  int left = 0;
  int right = citationsSize;

  while (left < right) {
    const int mid = (left + right) / 2;
    if (citations[mid] >= citationsSize - mid) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return citationsSize - left;
}
