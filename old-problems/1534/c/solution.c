int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
  int count = 0;
  for (int k = arrSize - 1; k >= 2; --k) {
    for (int j = k - 1; j >= 1; --j) {
      if (arr[j] - arr[k] > b || arr[j] - arr[k] < -b) continue;
      for (int i = j - 1; i >= 0; --i) {
        if (arr[i] - arr[j] <= a && arr[i] - arr[j] >= -a &&
            arr[i] - arr[k] <= c && arr[i] - arr[k] >= -c) ++count;
      }
    }
  }
  return count;
}
