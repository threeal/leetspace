int chalkReplacer(int* chalk, int chalkSize, int k) {
  if (k < chalk[0]) return 0;
  for (int i = 1; i < chalkSize; ++i) {
    if (k - chalk[i - 1] < chalk[i]) return i;
    chalk[i] += chalk[i - 1];
  }

  int l = 0, r = chalkSize - 1, target = k % chalk[chalkSize - 1];
  while (l < r) {
    const int mid = l + (r - l) / 2;
    if (chalk[mid] <= target) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  return l;
}
