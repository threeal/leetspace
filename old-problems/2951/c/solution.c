int* findPeaks(int* mountain, int mountainSize, int* returnSize) {
  int n = 0;
  for (int i = 2; i < mountainSize; ++i) {
    if (mountain[i - 2] < mountain[i - 1] && mountain[i - 1] > mountain[i]) {
      mountain[n++] = i - 1;
    }
  }
  *returnSize = n;
  return mountain;
}
