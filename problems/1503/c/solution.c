int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize) {
  int leftMax = 0;
  for (int i = 0; i < leftSize; ++i) {
    if (left[i] > leftMax) leftMax = left[i];
  }

  int rightMin = 10000;
  for (int i = 0; i < rightSize; ++i) {
    if (right[i] < rightMin) rightMin = right[i];
  }

  if (leftSize == 0) return n - rightMin;
  if (rightSize == 0) return leftMax;
  return (leftMax > n - rightMin) ? leftMax : n - rightMin;
}
