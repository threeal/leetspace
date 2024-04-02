int pivotInteger(int n) {
  if (n == 1) return 1;

  int left = 1;
  int right = n;

  while (left + 1 < right) {
    const int pivot = (left + right) / 2;
    const int leftSum = pivot * (1 + pivot);
    const int rightSum = (n + 1 - pivot) * (pivot + n);

    if (leftSum == rightSum) return pivot;

    if (leftSum < rightSum) {
      left = pivot;
    } else {
      right = pivot;
    }
  }

  return -1;
}
